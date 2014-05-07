import rospy
import roslib
import rosapi
import thread


roslib.load_manifest('rosapi')
roslib.load_manifest('std_msgs')
roslib.load_manifest('geometry_msgs')
roslib.load_manifest('gazebo_msgs')

from rosapi.srv import Topics
from rosapi.srv import TopicType

from std_msgs.msg import Float32
from std_msgs.msg import Bool
from geometry_msgs.msg import Twist
from gazebo_msgs.msg import ModelState

from threading import Thread


 
def init():
	try:
		rospy.init_node('transfer_function_wrapper')
	except rospy.exceptions.ROSInitException:
		print >> sys.stderr, 'brain_to_body is unable to initialize node. Master may not be running.'
		sys.exit(0)
		
	rospy.Subscriber("/simulation_control_server/experiment_finished", Bool, shutdown_callback)
		
	#global thread_ros
	#thread_ros = Thread(target=rospy.spin)
	#thread_ros.start()

def getRosTopics():
	print('HERE')
	rospy.wait_for_service('/rosapi/topics')
	try:
		rostopics = rospy.ServiceProxy('/rosapi/topics', Topics)
		topics = rostopics()
		return topics.topics
	except rospy.ServiceException, e:
		print "Service call failed: %s"%e
		
def getRosTopicType(topic_name):
	rospy.wait_for_service('/rosapi/topic_type')
	try:
		rostopictype = rospy.ServiceProxy('/rosapi/topic_type', TopicType)
		rostype = rostopictype(topic_name)
		return rostype.type
	except rospy.ServiceException, e:
		print "Service call failed: %s"%e
	
        	
def connectToNestData(data_topic, callback_function):
	print("Connecting to NEST data...")
	if data_topic == 'voltmeter':
		rospy.Subscriber("/nest/voltage", Float32, callback_function)
		
def getDataSendContainer(data_topic):
	if data_topic == 'cmd_vel':
		return Twist()
	elif data_topic == 'husky_sim_speed':
		model_state = ModelState()
		model_state.model_name = 'husky'
		return model_state
		
def sendToSimulator(data_topic, data):
	if data_topic == 'cmd_vel':
		cmd_vel_pub = rospy.Publisher('/husky/cmd_vel', Twist)
		cmd_vel_pub.publish(data)
	elif data_topic == 'husky_sim_speed':
		husky_vel_pub = rospy.Publisher('/gazebo/set_model_state', ModelState)
		husky_vel_pub.publish(data)
		
		
def run():
	try:
		rospy.spin()
	except (KeyboardInterrupt, SystemExit):
		rospy.signal_shutdown("Leaving")

def shutdown_callback(shutdown_msg):
	sys.exit()
		
#if __name__ == '__main__':
#	print 'APITest'
#	init()
#	topics = getRosTopics()
#	for topic in topics:
#		print(topic)
#		print(getRosTopicType(topic))
		
#	rospy.signal_shutdown("Leaving")
		
	
		
		
		


