
(cl:in-package :asdf)

(defsystem "map_generator-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ObjectTpyeArray" :depends-on ("_package_ObjectTpyeArray"))
    (:file "_package_ObjectTpyeArray" :depends-on ("_package"))
  ))