; Auto-generated. Do not edit!


(cl:in-package simulation_control_server-srv)


;//! \htmlinclude StartSimulation-request.msg.html

(cl:defclass <StartSimulation-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass StartSimulation-request (<StartSimulation-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartSimulation-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartSimulation-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulation_control_server-srv:<StartSimulation-request> is deprecated: use simulation_control_server-srv:StartSimulation-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartSimulation-request>) ostream)
  "Serializes a message object of type '<StartSimulation-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartSimulation-request>) istream)
  "Deserializes a message object of type '<StartSimulation-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartSimulation-request>)))
  "Returns string type for a service object of type '<StartSimulation-request>"
  "simulation_control_server/StartSimulationRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartSimulation-request)))
  "Returns string type for a service object of type 'StartSimulation-request"
  "simulation_control_server/StartSimulationRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartSimulation-request>)))
  "Returns md5sum for a message object of type '<StartSimulation-request>"
  "60bcc75747a184ebdba0e9c639470b9c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartSimulation-request)))
  "Returns md5sum for a message object of type 'StartSimulation-request"
  "60bcc75747a184ebdba0e9c639470b9c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartSimulation-request>)))
  "Returns full string definition for message of type '<StartSimulation-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartSimulation-request)))
  "Returns full string definition for message of type 'StartSimulation-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartSimulation-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartSimulation-request>))
  "Converts a ROS message object to a list"
  (cl:list 'StartSimulation-request
))
;//! \htmlinclude StartSimulation-response.msg.html

(cl:defclass <StartSimulation-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (error_string
    :reader error_string
    :initarg :error_string
    :type cl:string
    :initform ""))
)

(cl:defclass StartSimulation-response (<StartSimulation-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartSimulation-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartSimulation-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulation_control_server-srv:<StartSimulation-response> is deprecated: use simulation_control_server-srv:StartSimulation-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <StartSimulation-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulation_control_server-srv:success-val is deprecated.  Use simulation_control_server-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'error_string-val :lambda-list '(m))
(cl:defmethod error_string-val ((m <StartSimulation-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulation_control_server-srv:error_string-val is deprecated.  Use simulation_control_server-srv:error_string instead.")
  (error_string m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartSimulation-response>) ostream)
  "Serializes a message object of type '<StartSimulation-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'error_string))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'error_string))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartSimulation-response>) istream)
  "Deserializes a message object of type '<StartSimulation-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'error_string) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'error_string) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartSimulation-response>)))
  "Returns string type for a service object of type '<StartSimulation-response>"
  "simulation_control_server/StartSimulationResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartSimulation-response)))
  "Returns string type for a service object of type 'StartSimulation-response"
  "simulation_control_server/StartSimulationResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartSimulation-response>)))
  "Returns md5sum for a message object of type '<StartSimulation-response>"
  "60bcc75747a184ebdba0e9c639470b9c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartSimulation-response)))
  "Returns md5sum for a message object of type 'StartSimulation-response"
  "60bcc75747a184ebdba0e9c639470b9c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartSimulation-response>)))
  "Returns full string definition for message of type '<StartSimulation-response>"
  (cl:format cl:nil "bool success~%string error_string~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartSimulation-response)))
  "Returns full string definition for message of type 'StartSimulation-response"
  (cl:format cl:nil "bool success~%string error_string~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartSimulation-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'error_string))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartSimulation-response>))
  "Converts a ROS message object to a list"
  (cl:list 'StartSimulation-response
    (cl:cons ':success (success msg))
    (cl:cons ':error_string (error_string msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'StartSimulation)))
  'StartSimulation-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'StartSimulation)))
  'StartSimulation-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartSimulation)))
  "Returns string type for a service object of type '<StartSimulation>"
  "simulation_control_server/StartSimulation")