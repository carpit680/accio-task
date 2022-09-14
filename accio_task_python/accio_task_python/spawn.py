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
        {0.0: {
            "parkingX": 0.0,
            "parkingY": 0.0,
            "x": 0.0,
            "y": 0.0,
            "available": True,
            "dir": 0.0,
        }},
        {1.0: {
            "parkingX": 0.0,
            "parkingY": 100.0,
            "x": 0.0,
            "y": 100.0,
            "available": True,
            "dir": 0,
        }},
        {2.0: {
            "parkingX": 100.0,
            "parkingY": 0.0,
            "x": 100.0,
            "y": 0.0,
            "available": True,
            "dir": 0,
        }},
        {3.0: {
            "parkingX": 100.0,
            "parkingY": 100.0,
            "x": 100.0,
            "y": 100.0,
            "available": True,
            "dir": 0,
        }},
        {4.0: {
            "parkingX": 100.0,
            "parkingY": 50.0,
            "x": 100.0,
            "y": 50.0,
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
        self.pub = self.create_publisher(Robot, 'robot', 10)
        self.msg = Robot()
        # self.reset_robots()
        self.current_order = Order()
        self.timer = self.create_timer(1.0, self.timer_callback)

    def move_tote(self, robot_id, tote_id):
        """
        move robot to tote location and then move it to station
        """

        robot = graph["robots"][robot_id]
        tote = graph["totes"][tote_id]
        # print("1")
        self.msg.robot_id = float(robot_id)
        self.msg.available = False
        self.pub.publish(self.msg)

        # move to tote
        self.msg.position.x = tote[list(tote.keys())[0]]["x"]
        self.pub.publish(self.msg)
        time.sleep(5)
        self.msg.position.y = tote[list(tote.keys())[0]]["y"]
        self.pub.publish(self.msg)
        time.sleep(5)

        # move to station

        self.msg.position.x = graph["station"]["x"]
        self.pub.publish(self.msg)
        time.sleep(5)
        self.msg.position.y = graph["station"]["y"]
        self.pub.publish(self.msg)
        time.sleep(5)

        # move to parking
        self.msg.position.x = robot[list(robot.keys())[0]]["parkingX"]
        self.pub.publish(self.msg)
        time.sleep(5)
        self.msg.position.y = robot[list(robot.keys())[0]]["parkingY"]
        self.pub.publish(self.msg)
        time.sleep(5)

        self.msg.available = True
        self.pub.publish(self.msg)


    def move_tote_old(self, robot_id, tote_id):
        """
        move robot to tote location and then move it to station
        """

        robot = graph["robots"][robot_id]
        tote = graph["totes"][tote_id]
        # print("1")
        self.msg.robot_id = float(robot_id)
        self.msg.available = False
        self.pub.publish(self.msg)
        # print("2")

        stepsx = (tote[list(tote.keys())[0]]["x"] -
                  robot[list(robot.keys())[0]]["x"]) // graph["robot_speed"]
        stepsy = (tote[list(tote.keys())[0]]["y"] -
                  robot[list(robot.keys())[0]]["y"]) // graph["robot_speed"]
        # print("3")
        for i in range(int(abs(stepsx))):
            self.msg.position.x = robot[list(robot.keys())[0]]["x"]
            if stepsx > 0:
                self.msg.position.x += int(graph["robot_speed"])
            else:
                self.msg.position.x -= int(graph["robot_speed"])
            time.sleep(.5)
            self.pub.publish(self.msg)
        # print("4")

        for i in range(int(abs(stepsy))):
            self.msg.position.y = robot[list(robot.keys())[0]]["y"]
            if stepsx > 0:
                self.msg.position.y += int(graph["robot_speed"])
            else:
                self.msg.position.y -= int(graph["robot_speed"])
            time.sleep(.5)
            self.pub.publish(self.msg)
        # print("5")

        stepsx = (graph["station"]["x"] - tote[list(tote.keys())[0]]["x"]) // graph["robot_speed"]
        stepsy = (graph["station"]["y"] - tote[list(tote.keys())[0]]["y"]) // graph["robot_speed"]
        # print("6")

        for i in range(int(abs(stepsx))):
            self.msg.position.x = robot[list(robot.keys())[0]]["x"]
            if stepsx > 0:
                self.msg.position.x += int(graph["robot_speed"])
            else:
                self.msg.position.x -= int(graph["robot_speed"])
            time.sleep(.5)
            self.pub.publish(self.msg)
        # print("7")

        for i in range(int(abs(stepsy))):
            self.msg.position.y = robot[list(robot.keys())[0]]["y"]
            if stepsx > 0:
                self.msg.position.y += int(graph["robot_speed"])
            else:
                self.msg.position.y -= int(graph["robot_speed"])
            time.sleep(.5)
            self.pub.publish(self.msg)
        # print("8")

        stepsx = (robot[list(robot.keys())[0]]["parkingX"] - graph["station"]
                ["x"]) // graph["robot_speed"]
        stepsy = (robot[list(robot.keys())[0]]["parkingY"] - graph["station"]
                ["y"]) // graph["robot_speed"]
        # print("9")

        for i in range(int(abs(stepsx))):
            self.msg.position.x = robot[list(robot.keys())[0]]["x"]
            if stepsx > 0:
                self.msg.position.x += int(graph["robot_speed"])
            else:
                self.msg.position.x -= int(graph["robot_speed"])
            time.sleep(.5)
            self.pub.publish(self.msg)
        # print("10")

        for i in range(int(abs(stepsy))):
            self.msg.position.y = robot[list(robot.keys())[0]]["y"]
            if stepsx > 0:
                self.msg.position.y += int(graph["robot_speed"])
            else:
                self.msg.position.y -= int(graph["robot_speed"])
            time.sleep(.5)
            self.pub.publish(self.msg)
        # print("11")

        self.msg.available = True
        self.pub.publish(self.msg)

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
        # check if robot 0 is available

        if graph["robots"][0][list(graph["robots"][0].keys())[0]]["available"]:
            if len(PENDING_ORDERS) > 0:
                # self.current_order = PENDING_ORDERS[0]
                pending_order_copy = PENDING_ORDERS.copy()
                for current_order in pending_order_copy:
                    for tote in current_order.picklist:
                        time.sleep(1)
                        for robot in graph["robots"]:

                            if robot[list(robot.keys())[0]]["available"]:
                                robot_id = list(robot.keys())[0]
                                self.move_tote(int(robot_id), int(tote))

                                PENDING_ORDERS[PENDING_ORDERS.index(
                                    current_order)].picklist.remove(tote)
                                break
                            else:
                                time.sleep(1)
                                continue

                    # if len(PENDING_ORDERS[PENDING_ORDERS.index(
                    #         current_order)].picklist) == 0:
                    FULFILLED_ORDERS.append(current_order.orderid)
                    PENDING_ORDERS.remove(current_order)


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
        fulfilled_order_publisher = FulfilledOrderPublisher()
        executor = MultiThreadedExecutor(num_threads=20)
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
