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
from accio_interfaces.msg import OrdersFulfilled  # pylint: disable=import-error
from accio_interfaces.msg import RobotList  # pylint: disable=import-error
import time

lock = Lock()
PENDING_ORDERS = []
FULFILLED_ORDERS = []
ROBOTS = []

graph = {
    "maxX": 100.0,
    "maxY": 100.0,
    "totes": [
        {1.0: {
            "x": 10.0,
            "y": 20.0,
        }},
        {2.0: {
            "x": 30.0,
            "y": 10.0,
        }},
        {3.0: {
            "x": 80.0,
            "y": 30.0,
        }},
        {4.0: {
            "x": 50.0,
            "y": 50.0,
        }},
        {5.0: {
            "x": 40.0,
            "y": 70.0,
        }},
        {6.0: {
            "x": 70.0,
            "y": 80.0,
        }},
        {7.0: {
            "x": 90.0,
            "y": 90.0,
        }},
        {8.0: {
            "x": 20.0,
            "y": 90.0,
        }},
        {9.0: {
            "x": 10.0,
            "y": 10.0,
        }},
        {10.0: {
            "x": 30.0,
            "y": 30.0,
        }},
    ],
    "robots": [
        {1.0: {
            "parkingX": 0.0,
            "parkingY": 0.0,
            "x": 0.0,
            "y": 0.0,
            "available": True,
            "dir": 0.0,
        }},
        {2.0: {
            "parkingX": 0.0,
            "parkingY": 100.0,
            "x": 0.0,
            "y": 100.0,
            "available": True,
            "dir": 0,
        }},
        {3.0: {
            "parkingX": 100.0,
            "parkingY": 0.0,
            "x": 100.0,
            "y": 0.0,
            "available": True,
            "dir": 0,
        }},
        {4.0: {
            "parkingX": 100.0,
            "parkingY": 100.0,
            "x": 100.0,
            "y": 100.0,
            "available": True,
            "dir": 0,
        }}
    ],
    "station": {
        "x": 50.0,
        "y": 100.0,
    },
    "robot_speed": 5,
    "max_steps": 20,
}


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

        order = Order()
        order.orderid = msg.orderid
        for tote in msg.picklist:
            order.picklist.append(int(tote))
        # order.picklist = msg.picklist
        # lock.acquire()
        PENDING_ORDERS.append(order)
        print("inside order callback")
        # lock.release()


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
        self.pub = self.create_publisher(RobotList, 'robot', 10)
        self.msg = RobotList()
        self.reset_robots()
        self.current_order = Order()
        self.timer = self.create_timer(1.0, self.timer_callback)

    def reset_robots(self):
        """
        setup_robots

        ...

        Parameters
        ----------
        None

        Returns
        -------
        None
        """
        for robot in graph["robots"]:
            init = Robot()
            init.robot_id = float(list(robot.keys())[0])
            init.available = robot[list(robot.keys())[0]]["available"]
            init.position.x = robot[list(robot.keys())[0]]["x"]
            init.position.y = robot[list(robot.keys())[0]]["x"]
            # init.direction = int(robot[init.robot_id]["dir"])
            self.msg.robot_list.append(init)

    def move_to_tote(self, robot_id, tote_id):
        """
        move robot to tote location and then move it to station
        """

        robot = graph["robots"][robot_id]
        tote = graph["totes"][tote_id]
        for item in self.msg.robot_list:
            if int(item.robot_id) == robot_id:

                item.position.x = robot[list(robot.keys())[0]]["x"]
                item.position.y = robot[list(robot.keys())[0]]["y"]
                item.available = False
                robot["available"] = False

                # self.msg.robot_id = robot_i
                stepsx = (tote[list(tote.keys())[0]]["x"] -
                          robot[list(robot.keys())[0]]["x"]) / graph["robot_speed"]
                stepsy = (tote[list(tote.keys())[0]]["y"] -
                          robot[list(robot.keys())[0]]["y"]) / graph["robot_speed"]
                # self.get_logger().info(f'Robot {robot_id} moving to tote {tote_id}')
                for i in range(int(stepsx)):
                    item.position.x += int(graph["robot_speed"])
                    self.msg.robot_list[robot_id] = item
                    self.pub.publish(self.msg)
                    # self.get_logger().info(
                    #     f'moving {robot_id}to x: {item.position.x}')
                for i in range(int(stepsy)):
                    item.position.y += int(graph["robot_speed"])
                    self.msg.robot_list[robot_id] = item
                    self.pub.publish(self.msg)
                    # self.get_logger().info(
                    #     f'moving {robot}to y: {item.position.y}')
                # self.get_logger().info(f'Robot {robot_id} moving to station')
                stepsx = (
                    graph["station"]["x"] - tote[list(tote.keys())[0]]["x"]) // graph["robot_speed"]
                stepsy = (
                    graph["station"]["y"] - tote[list(tote.keys())[0]]["y"]) // graph["robot_speed"]
                for i in range(stepsx):
                    item.position.x += int(graph["robot_speed"])
                    self.msg.robot_list[robot_id] = item
                    self.pub.publish(self.msg)
                    # self.get_logger().info(
                    #     f'moving {robot}to x: {item.position.x}')
                for i in range(stepsy):
                    item.position.y += int(graph["robot_speed"])
                    self.msg.robot_list[robot_id] = item
                    self.pub.publish(self.msg)
                    # self.get_logger().info(
                    #     f'moving {robot}to y: {item.position.y}')
                # move robot back to parking spot
                # self.get_logger().info(f'Robot {robot_id} moving to parking spot')
                stepsx = (robot[list(robot.keys())[0]]["parkinX"] - graph["station"]
                        ["x"]) // graph["robot_speed"]
                stepsy = (robot[list(robot.keys())[0]]["parkingY"] - graph["station"]
                        ["y"]) // graph["robot_speed"]
                for i in range(stepsx):
                    item.position.x += int(graph["robot_speed"])
                    self.msg.robot_list[robot_id] = item
                    self.pub.publish(self.msg)
                    # self.get_logger().info(
                    #     f'moving {robot}to x: {item.position.x}')
                for i in range(stepsy):
                    item.position.y += int(graph["robot_speed"])
                    self.msg.robot_list[robot_id] = item
                    self.pub.publish(self.msg)
                    # self.get_logger().info(
                    #     f'moving {robot}to y: {item.position.y}')

                item.available = True
                robot["available"] = True
                item.position.x = robot[list(robot.keys())[
                    0]]["parkingX"]
                item.position.y = robot[list(robot.keys())[
                    0]]["parkingY"]
                self.msg.robot_list[robot_id] = item
                self.pub.publish(self.msg)
                return

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
        if len(PENDING_ORDERS) > 0:
            # self.current_order = PENDING_ORDERS[0]
            for current_order in PENDING_ORDERS:
                for tote in current_order.picklist:
                    time.sleep(1)
                    for robot in graph["robots"]:
                        
                        if robot[list(robot.keys())[0]]["available"]:
                            robot_id = list(robot.keys())[0]
                            # self.move_to_tote(int(robot_id), int(tote))
                            break

                    PENDING_ORDERS[PENDING_ORDERS.index(
                        current_order)].picklist.remove(tote)
                if current_order in PENDING_ORDERS:
                    FULFILLED_ORDERS.append(
                        PENDING_ORDERS.pop(PENDING_ORDERS.index(current_order)).orderid)


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
        self.prev_msg = None

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

        if len(PENDING_ORDERS) > 0 and self.prev_msg != PENDING_ORDERS:
            self.prev_msg = PENDING_ORDERS.copy()
            self.msg = Orders()
            for order in PENDING_ORDERS:
                self.msg.orders.append(order)
            print("inside pending callback")
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
        self.msg = OrdersFulfilled()
        self.pub = self.create_publisher(
            OrdersFulfilled, 'orders_fulfilled', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.prev_list = None

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
        if FULFILLED_ORDERS != self.prev_list and len(FULFILLED_ORDERS) > 0:
            self.prev_list = FULFILLED_ORDERS.copy()
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
        # fulfilled_order_publisher = FulfilledOrderPublisher()
        executor = MultiThreadedExecutor(num_threads=20)
        executor.add_node(order_handler)
        executor.add_node(robot_publisher)
        executor.add_node(pending_order_publisher)
        # executor.add_node(fulfilled_order_publisher)

        try:
            executor.spin()
        finally:
            executor.shutdown()
            order_handler.destroy_node()
            robot_publisher.destroy_node()
            pending_order_publisher.destroy_node()
            # fulfilled_order_publisher.destroy_node()
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
