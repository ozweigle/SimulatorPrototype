#!/usr/bin/python
#
# main.py
# Copyright (C) 2013 ozweigle1 <ozweigle1@ozweigle1-Parallels-Virtual-Platform>
# 

import rospy
import roslib
roslib.load_manifest('node_control_server')

import traceback
import threading
import copy
threading._DummyThread._Thread__stop = lambda x: 42

from threading import Timer
import sys, os, time
import getopt
from time import sleep
import subprocess
import string
import re
import std_msgs
from node_control_server.msg import NodeControl


diag_hostname = 'ScanBot'

    
    
def process_exists(proc_name):
	ps = subprocess.Popen("ps ax -o pid= -o args= ", shell=True, stdout=subprocess.PIPE)
	ps_pid = ps.pid
	output = ps.stdout.read()
	ps.stdout.close()
	ps.wait()
	
	for line in output.split("\n"):
		res = re.findall("(\d+) (.*)", line)
		if res:
			pid = int(res[0][0])
			if proc_name in res[0][1] and pid != os.getpid() and pid != ps_pid:
				return True
	return False

def bool_string_convert(boolstring):
	if boolstring == "True" or boolstring == "TRUE" or boolstring == "true":
		return True
	else:
		return False
	
def generate_node_control_msg(nodename, run, shutdown):
	msg = NodeControl()
	msg.name.data = nodename
	msg.run.data = run
	msg.shut_down.data = shutdown
	return msg
	
if __name__ == '__main__':
	nodename = ""
	run = False
	run_defined = False
	shutdown = False
	shutdown_defined = False
	usageString = 'Usage: node_control_sender.py --nodename=<nodename> --run=<True/False> --shutdown=<True/False>'
	
	#counter = 0
	#for arg in sys.argv:
	#	print arg
		
	try:
		opts, args = getopt.getopt(sys.argv[1:],"hi:o:",["nodename=","run=","shutdown="])
	except getopt.GetoptError:
		print usageString
		sys.exit(2)
	for opt, arg in opts:
		if opt == '-h':
			print usageString
			sys.exit()
		elif opt == ("--nodename"):
			nodename = arg
		elif opt == ("--run"):
			run = bool_string_convert(arg)
			run_defined = True
		elif opt == ("--shutdown"):
			shutdown = bool_string_convert(arg)
			shutdown_defined = True
	
	if nodename == "" or not run_defined or not shutdown_defined:
		print "Error. All arguments have to be set!"
		print usageString
		sys.exit()
	
	
	try:
		rospy.init_node('node_control_sender')
	except rospy.exceptions.ROSInitException:
		print >> sys.stderr, 'node_control_sender is unable to initialize node. Master may not be running.'
		sys.exit(0)

	
	node_pub = rospy.Publisher('NodeControlServer/nodeControl', NodeControl)
	sleep(1)
	
	r = rospy.Rate(1)
	counter = 0
	try:
		print "Sending message to NodeControlServer....."
		while not rospy.is_shutdown() and counter < 1:
			node_pub.publish(generate_node_control_msg(nodename, run, shutdown))
			r.sleep()
			counter = counter + 1
	except KeyboardInterrupt:
			pass
	except Exception, e:
		traceback.print_exc()
		rospy.logerr(traceback.format_exc())
		
	print "Published NodeControl Message successfully"

	sys.exit(0)
    

