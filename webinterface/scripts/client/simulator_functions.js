var simulator_functions = simulator_functions || {};

function setTransferFunctionService(file_name, callback_function) {

    var setTransferFunctionClient = new ROSLIB.Service({
                                                           ros : connection,
                                                           name : '/simulation_control_server/set_transfer_function',
                                                           serviceType : 'simulation_controlServer/SetTransferFunction'
                                                       });

    var request = new ROSLIB.ServiceRequest({
                                                transfer_function_name : file_name,
                                            });

    setTransferFunctionClient.callService(request, callback_function);

}
