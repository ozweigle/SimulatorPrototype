import transfer_functions

def brain_voltage_data_callback(brain_voltage):
	vel_msg = transfer_functions.getDataSendContainer("cmd_vel")
	print(brain_voltage.data)
	if brain_voltage.data < -75.0:
		vel_msg.linear.x = 3.0
		vel_msg.linear.y = 0.0
		vel_msg.linear.z = 0.0
		vel_msg.angular.x = 0.0
		vel_msg.angular.y = 0.0
		vel_msg.angular.z = 0.0
		transfer_functions.sendToSimulator("cmd_vel", vel_msg)
	elif brain_voltage.data > -75.0:
		vel_msg.linear.x = 0.0
		vel_msg.linear.y = 0.0
		vel_msg.linear.z = 0.0
		vel_msg.angular.x = 0.0
		vel_msg.angular.y = 0.0
		vel_msg.angular.z = 0.0
		transfer_functions.sendToSimulator("cmd_vel", vel_msg)
		
			
if __name__ == '__main__':
	print 'trans_func_test1 running...'
	

	transfer_functions.init()
	transfer_functions.connectToNestData("voltmeter", brain_voltage_data_callback)
	
	transfer_functions.run()		
	
