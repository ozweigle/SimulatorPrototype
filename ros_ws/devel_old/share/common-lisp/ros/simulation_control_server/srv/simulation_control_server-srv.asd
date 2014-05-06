
(cl:in-package :asdf)

(defsystem "simulation_control_server-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ExecuteCommand" :depends-on ("_package_ExecuteCommand"))
    (:file "_package_ExecuteCommand" :depends-on ("_package"))
    (:file "SetTransferFunction" :depends-on ("_package_SetTransferFunction"))
    (:file "_package_SetTransferFunction" :depends-on ("_package"))
    (:file "StartSimulation" :depends-on ("_package_StartSimulation"))
    (:file "_package_StartSimulation" :depends-on ("_package"))
  ))