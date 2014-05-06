
(cl:in-package :asdf)

(defsystem "simulation_control_server-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "SimulationControl" :depends-on ("_package_SimulationControl"))
    (:file "_package_SimulationControl" :depends-on ("_package"))
    (:file "SimulationControl" :depends-on ("_package_SimulationControl"))
    (:file "_package_SimulationControl" :depends-on ("_package"))
  ))