; Auto-generated. Do not edit!


(cl:in-package simulation_control_server-srv)


;//! \htmlinclude SetTransferFunction-request.msg.html

(cl:defclass <SetTransferFunction-request> (roslisp-msg-protocol:ros-message)
  ((transfer_function_name
    :reader transfer_function_name
    :initarg :transfer_function_name
    :type cl:string
    :initform ""))
)

(cl:defclass SetTransferFunction-request (<SetTransferFunction-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetTransferFunction-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetTransferFunction-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulation_control_server-srv:<SetTransferFunction-request> is deprecated: use simulation_control_server-srv:SetTransferFunction-request instead.")))

(cl:ensure-generic-function 'transfer_function_name-val :lambda-list '(m))
(cl:defmethod transfer_function_name-val ((m <SetTransferFunction-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulation_control_server-srv:transfer_function_name-val is deprecated.  Use simulation_control_server-srv:transfer_function_name instead.")
  (transfer_function_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetTransferFunction-request>) ostream)
  "Serializes a message object of type '<SetTransferFunction-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'transfer_function_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'transfer_function_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetTransferFunction-request>) istream)
  "Deserializes a message object of type '<SetTransferFunction-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'transfer_function_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'transfer_function_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetTransferFunction-request>)))
  "Returns string type for a service object of type '<SetTransferFunction-request>"
  "simulation_control_server/SetTransferFunctionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetTransferFunction-request)))
  "Returns string type for a service object of type 'SetTransferFunction-request"
  "simulation_control_server/SetTransferFunctionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetTransferFunction-request>)))
  "Returns md5sum for a message object of type '<SetTransferFunction-request>"
  "379f039a7ed7ce5891d0e1b19aba0f55")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetTransferFunction-request)))
  "Returns md5sum for a message object of type 'SetTransferFunction-request"
  "379f039a7ed7ce5891d0e1b19aba0f55")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetTransferFunction-request>)))
  "Returns full string definition for message of type '<SetTransferFunction-request>"
  (cl:format cl:nil "string transfer_function_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetTransferFunction-request)))
  "Returns full string definition for message of type 'SetTransferFunction-request"
  (cl:format cl:nil "string transfer_function_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetTransferFunction-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'transfer_function_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetTransferFunction-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetTransferFunction-request
    (cl:cons ':transfer_function_name (transfer_function_name msg))
))
;//! \htmlinclude SetTransferFunction-response.msg.html

(cl:defclass <SetTransferFunction-response> (roslisp-msg-protocol:ros-message)
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

(cl:defclass SetTransferFunction-response (<SetTransferFunction-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetTransferFunction-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetTransferFunction-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulation_control_server-srv:<SetTransferFunction-response> is deprecated: use simulation_control_server-srv:SetTransferFunction-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetTransferFunction-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulation_control_server-srv:success-val is deprecated.  Use simulation_control_server-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'error_string-val :lambda-list '(m))
(cl:defmethod error_string-val ((m <SetTransferFunction-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulation_control_server-srv:error_string-val is deprecated.  Use simulation_control_server-srv:error_string instead.")
  (error_string m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetTransferFunction-response>) ostream)
  "Serializes a message object of type '<SetTransferFunction-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'error_string))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'error_string))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetTransferFunction-response>) istream)
  "Deserializes a message object of type '<SetTransferFunction-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetTransferFunction-response>)))
  "Returns string type for a service object of type '<SetTransferFunction-response>"
  "simulation_control_server/SetTransferFunctionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetTransferFunction-response)))
  "Returns string type for a service object of type 'SetTransferFunction-response"
  "simulation_control_server/SetTransferFunctionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetTransferFunction-response>)))
  "Returns md5sum for a message object of type '<SetTransferFunction-response>"
  "379f039a7ed7ce5891d0e1b19aba0f55")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetTransferFunction-response)))
  "Returns md5sum for a message object of type 'SetTransferFunction-response"
  "379f039a7ed7ce5891d0e1b19aba0f55")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetTransferFunction-response>)))
  "Returns full string definition for message of type '<SetTransferFunction-response>"
  (cl:format cl:nil "bool success~%string error_string~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetTransferFunction-response)))
  "Returns full string definition for message of type 'SetTransferFunction-response"
  (cl:format cl:nil "bool success~%string error_string~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetTransferFunction-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'error_string))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetTransferFunction-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetTransferFunction-response
    (cl:cons ':success (success msg))
    (cl:cons ':error_string (error_string msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetTransferFunction)))
  'SetTransferFunction-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetTransferFunction)))
  'SetTransferFunction-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetTransferFunction)))
  "Returns string type for a service object of type '<SetTransferFunction>"
  "simulation_control_server/SetTransferFunction")