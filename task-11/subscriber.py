#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def sender():
    pub = rospy.Publisher('publish', String, queue_size=10)
    rospy.init_node('sender', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        hello_str = "welcome to smart methods %s" % rospy.get_time()
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        sender()
    except rospy.ROSInterruptException:
        pass
