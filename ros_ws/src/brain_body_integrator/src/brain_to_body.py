import rospy
import roslib

roslib.load_manifest('std_msgs')
roslib.load_manifest('geometry_msgs')
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist

cmd_vel_pub = rospy.Publisher('/cmd_vel', Twist)

def brain_voltage_data_callback(brain_voltage):
	#print(brain_voltage.data)
	if brain_voltage.data < -75.0:
		vel_msg = Twist()
		vel_msg.linear.x = 3.0
		vel_msg.linear.y = 0.0
		vel_msg.linear.z = 0.0
		vel_msg.angular.x = 0.0
		vel_msg.angular.y = 0.0
		vel_msg.angular.z = 0.0
		cmd_vel_pub.publish(vel_msg)
	elif brain_voltage.data > -75.0:
		vel_msg = Twist()
		vel_msg.linear.x = 0.0
		vel_msg.linear.y = 0.0
		vel_msg.linear.z = 0.0
		vel_msg.angular.x = 0.0
		vel_msg.angular.y = 0.0
		vel_msg.angular.z = 0.0
		cmd_vel_pub.publish(vel_msg)
		
			
if __name__ == '__main__':
	print 'BrainToBody'
	try:
		rospy.init_node('brain_to_body')
	except rospy.exceptions.ROSInitException:
		print >> sys.stderr, 'brain_to_body is unable to initialize node. Master may not be running.'
		sys.exit(0)

	
	rospy.Subscriber("/nest/voltage", Float32, brain_voltage_data_callback)
	
			
	rate = rospy.Rate(30.0)
	rospy.spin()

