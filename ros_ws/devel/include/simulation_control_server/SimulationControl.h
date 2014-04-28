/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /media/psf/Home/SVNReps/HBPGit/SimulatorPrototype/ros_ws/src/simulation_control_server/msg/SimulationControl.msg
 *
 */


#ifndef SIMULATION_CONTROL_SERVER_MESSAGE_SIMULATIONCONTROL_H
#define SIMULATION_CONTROL_SERVER_MESSAGE_SIMULATIONCONTROL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Bool.h>

namespace simulation_control_server
{
template <class ContainerAllocator>
struct SimulationControl_
{
  typedef SimulationControl_<ContainerAllocator> Type;

  SimulationControl_()
    : header()
    , name()
    , run()
    , shut_down()  {
    }
  SimulationControl_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , name(_alloc)
    , run(_alloc)
    , shut_down(_alloc)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::String_<ContainerAllocator>  _name_type;
  _name_type name;

   typedef  ::std_msgs::Bool_<ContainerAllocator>  _run_type;
  _run_type run;

   typedef  ::std_msgs::Bool_<ContainerAllocator>  _shut_down_type;
  _shut_down_type shut_down;




  typedef boost::shared_ptr< ::simulation_control_server::SimulationControl_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::simulation_control_server::SimulationControl_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct SimulationControl_

typedef ::simulation_control_server::SimulationControl_<std::allocator<void> > SimulationControl;

typedef boost::shared_ptr< ::simulation_control_server::SimulationControl > SimulationControlPtr;
typedef boost::shared_ptr< ::simulation_control_server::SimulationControl const> SimulationControlConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::simulation_control_server::SimulationControl_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::simulation_control_server::SimulationControl_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace simulation_control_server

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'simulation_control_server': ['/media/psf/Home/SVNReps/HBPGit/SimulatorPrototype/ros_ws/src/simulation_control_server/msg', '/media/psf/Home/SVNReps/HBPGit/SimulatorPrototype/ros_ws/src/simulation_control_server/msg'], 'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::simulation_control_server::SimulationControl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::simulation_control_server::SimulationControl_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulation_control_server::SimulationControl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulation_control_server::SimulationControl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulation_control_server::SimulationControl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulation_control_server::SimulationControl_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::simulation_control_server::SimulationControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ae56be99d4cf2d13837f323d164ac16c";
  }

  static const char* value(const ::simulation_control_server::SimulationControl_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xae56be99d4cf2d13ULL;
  static const uint64_t static_value2 = 0x837f323d164ac16cULL;
};

template<class ContainerAllocator>
struct DataType< ::simulation_control_server::SimulationControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "simulation_control_server/SimulationControl";
  }

  static const char* value(const ::simulation_control_server::SimulationControl_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::simulation_control_server::SimulationControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/String name\n\
std_msgs/Bool run\n\
std_msgs/Bool shut_down\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: std_msgs/String\n\
string data\n\
\n\
================================================================================\n\
MSG: std_msgs/Bool\n\
bool data\n\
";
  }

  static const char* value(const ::simulation_control_server::SimulationControl_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::simulation_control_server::SimulationControl_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.name);
      stream.next(m.run);
      stream.next(m.shut_down);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct SimulationControl_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::simulation_control_server::SimulationControl_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::simulation_control_server::SimulationControl_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "name: ";
    s << std::endl;
    Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "  ", v.name);
    s << indent << "run: ";
    s << std::endl;
    Printer< ::std_msgs::Bool_<ContainerAllocator> >::stream(s, indent + "  ", v.run);
    s << indent << "shut_down: ";
    s << std::endl;
    Printer< ::std_msgs::Bool_<ContainerAllocator> >::stream(s, indent + "  ", v.shut_down);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIMULATION_CONTROL_SERVER_MESSAGE_SIMULATIONCONTROL_H
