"""
SPAWN

This module is responsible for spawning the subscriber for /order_list
publisher for /robot, /orders_queued, and /orders_fulfilled

I made this node because even after spending a good amount of time
I was unable to get the spawn_graph_robots_totes_new to work properly.

This is just to assist in the development and demo-ing of the web-interface.
"""

from threading import Lock
import rclpy  # pylint: disable=import-error
from rclpy.executors import MultiThreadedExecutor  # pylint: disable=import-error
from rclpy.node import Node  # pylint: disable=import-error
from accio_interfaces.msg import Order  # pylint: disable=import-error
from accio_interfaces.msg import Robot  # pylint: disable=import-error
from accio_interfaces.msg import Orders  # pylint: disable=import-error

lock = Lock()
PENDING_ORDERS = []
FULFILLED_ORDERS = []


class OrderHandler(Node):
    """
    OrderHandler

    ...

    Parameters
    ----------
    None

    Returns
    -------
    None
    """

    def __init__(self):
        super().__init__('order_handler')
        self.sub = self.create_subscription(
            Order, 'order_list', self.order_callback, 10)

    def order_callback(self, msg):
        """
        order_callback

        ...

        Parameters
        ----------
        msg : Order
            The order message

        Returns
        -------
        None
        """

        self.get_logger().info(f'Order received: {msg.orderid}')
        lock.acquire()
        PENDING_ORDERS.append(float(msg.orderid))
        lock.release()


class RobotPublisher(Node):
    """
    RobotPublisher

    ...

    Parameters
    ----------
    None

    Returns
    -------
    None
    """

    def __init__(self):
        super().__init__('robot_publisher')
        self.msg = Robot()
        self.msg.robot_id = 1.0
        self.msg.position.x, self.msg.position.y, self.msg.position.z = 0.0, 0.0, 0.0
        self.msg.orientation.qx = 0.0
        self.msg.orientation.qy = 0.0
        self.msg.orientation.qz = 0.0
        self.msg.orientation.qw = 0.0
        self.msg.available = True
        self.current_order = None
        self.prev_state = True
        self.pub = self.create_publisher(Robot, 'robot', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.counter = 0

    def timer_callback(self):
        """
        timer_callback

        ...

        Parameters
        ----------
        None

        Returns
        -------
        None
        """

        if len(PENDING_ORDERS) > 0 and self.msg.available:
            self.msg.available = False
            self.msg.position.x = 0.0
            self.msg.position.y = 0.0
            self.msg.position.z = 0.0
            lock.acquire()
            self.current_order = PENDING_ORDERS.pop()
            lock.release()
            self.get_logger().info(
                f'robot {self.msg.robot_id} is now handling {self.current_order}')
        elif self.current_order is not None and not self.msg.available:
            self.msg.position.x += 5.0
            self.msg.position.y += 5.0
            self.msg.position.z += 5.0
            self.counter += 1
            if self.counter == 10:
                self.msg.available = True
                self.counter = 0
                self.get_logger().info(
                    f'robot {self.msg.robot_id} has finished {self.current_order}')
                lock.acquire()
                FULFILLED_ORDERS.append(self.current_order)
                self.current_order = None
                lock.release()

        else:
            self.msg.position.x = 0.0
            self.msg.position.y = 0.0
            self.msg.position.z = 0.0

        self.pub.publish(self.msg)


class PendingOrderPublisher(Node):
    """
    PendingOrderPublisher

    ...

    Parameters
    ----------
    None

    Returns
    -------
    None
    """

    def __init__(self):
        super().__init__('pending_order_publisher')
        self.msg = Orders()
        self.pub = self.create_publisher(Orders, 'orders_queued', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        """
        timer_callback

        ...

        Parameters
        ----------
        None

        Returns
        -------
        None
        """

        if PENDING_ORDERS != list(self.msg.orders) and len(PENDING_ORDERS) > 0:
            self.get_logger().info(
                f'Publishing pending orders list{PENDING_ORDERS}{self.msg.orders}')
            self.msg.orders = PENDING_ORDERS.copy()
            self.pub.publish(self.msg)


class FulfilledOrderPublisher(Node):
    """
    FulfilledOrderPublisher

    ...

    Parameters
    ----------
    None

    Returns
    -------
    None
    """

    def __init__(self):
        super().__init__('fulfilled_order_publisher')
        self.msg = Orders()
        self.pub = self.create_publisher(Orders, 'orders_fulfilled', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        """
        timer_callback

        ...

        Parameters
        ----------
        None

        Returns
        -------
        None
        """
        if FULFILLED_ORDERS != list(self.msg.orders) and len(FULFILLED_ORDERS) > 0:
            self.get_logger().info(
                f'Publishing fulfilled orders list{FULFILLED_ORDERS}{self.msg.orders}')
            self.msg.orders = FULFILLED_ORDERS.copy()
            self.pub.publish(self.msg)


def main(args=None):
    """
    main

    ...

    Parameters
    ----------
    args : list
        The list of arguments

    Returns
    -------
    None
    """

    rclpy.init(args=args)
    try:
        order_handler = OrderHandler()
        robot_publisher = RobotPublisher()
        pending_order_publisher = PendingOrderPublisher()
        fulfilled_order_publisher = FulfilledOrderPublisher()
        executor = MultiThreadedExecutor(num_threads=10)
        executor.add_node(order_handler)
        executor.add_node(robot_publisher)
        executor.add_node(pending_order_publisher)
        executor.add_node(fulfilled_order_publisher)

        try:
            executor.spin()
        finally:
            executor.shutdown()
            order_handler.destroy_node()
            robot_publisher.destroy_node()
            pending_order_publisher.destroy_node()
            fulfilled_order_publisher.destroy_node()
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
