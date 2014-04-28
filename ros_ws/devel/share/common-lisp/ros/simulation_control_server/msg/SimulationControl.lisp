; Auto-generated. Do not edit!


(cl:in-package simulation_control_server-msg)


;//! \htmlinclude SimulationControl.msg.html

(cl:defclass <SimulationControl> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (name
    :reader name
    :initarg :name
    :type std_msgs-msg:String
    :initform (cl:make-instance 'std_msgs-msg:String))
   (run
    :reader run
    :initarg :run
    :type std_msgs-msg:Bool
    :initform (cl:make-instance 'std_msgs-msg:Bool))
   (shut_down
    :reader shut_down
    :initarg :shut_down
    :type std_msgs-msg:Bool
    :initform (cl:make-instance 'std_msgs-msg:Bool)))
)

(cl:defclass SimulationControl (<SimulationControl>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SimulationControl>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SimulationControl)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulation_control_server-msg:<SimulationControl> is deprecated: use simulation_control_server-msg:SimulationControl instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SimulationControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulation_control_server-msg:header-val is deprecated.  Use simulation_control_server-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <SimulationControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulation_control_server-msg:name-val is deprecated.  Use simulation_control_server-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'run-val :lambda-list '(m))
(cl:defmethod run-val ((m <SimulationControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulation_control_server-msg:run-val is deprecated.  Use simulation_control_server-msg:run instead.")
  (run m))

(cl:ensure-generic-function 'shut_down-val :lambda-list '(m))
(cl:defmethod shut_down-val ((m <SimulationControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulation_control_server-msg:shut_down-val is deprecated.  Use simulation_control_server-msg:shut_down instead.")
  (shut_down m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SimulationControl>) ostream)
  "Serializes a message object of type '<SimulationControl>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'name) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'run) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'shut_down) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SimulationControl>) istream)
  "Deserializes a message object of type '<SimulationControl>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'name) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'run) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'shut_down) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SimulationControl>)))
  "Returns string type for a message object of type '<SimulationControl>"
  "simulation_control_server/SimulationControl")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SimulationControl)))
  "Returns string type for a message object of type 'SimulationControl"
  "simulation_control_server/SimulationControl")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SimulationControl>)))
  "Returns md5sum for a message object of type '<SimulationControl>"
  "ae56be99d4cf2d13837f323d164ac16c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SimulationControl)))
  "Returns md5sum for a message object of type 'SimulationControl"
  "ae56be99d4cf2d13837f323d164ac16c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SimulationControl>)))
  "Returns full string definition for message of type '<SimulationControl>"
  (cl:format cl:nil "Header header~%std_msgs/String name~%std_msgs/Bool run~%std_msgs/Bool shut_down~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/String~%string data~%~%================================================================================~%MSG: std_msgs/Bool~%bool data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SimulationControl)))
  "Returns full string definition for message of type 'SimulationControl"
  (cl:format cl:nil "Header header~%std_msgs/String name~%std_msgs/Bool run~%std_msgs/Bool shut_down~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/String~%string data~%~%================================================================================~%MSG: std_msgs/Bool~%bool data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SimulationControl>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'name))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'run))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'shut_down))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SimulationControl>))
  "Converts a ROS message object to a list"
  (cl:list 'SimulationControl
    (cl:cons ':header (header msg))
    (cl:cons ':name (name msg))
    (cl:cons ':run (run msg))
    (cl:cons ':shut_down (shut_down msg))
))
