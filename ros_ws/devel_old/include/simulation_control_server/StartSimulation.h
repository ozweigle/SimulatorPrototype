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
 * Auto-generated by gensrv_cpp from file /media/psf/Home/SVNReps/HBPGit/SimulatorPrototype/ros_ws/src/simulation_control_server/srv/StartSimulation.srv
 *
 */


#ifndef SIMULATION_CONTROL_SERVER_MESSAGE_STARTSIMULATION_H
#define SIMULATION_CONTROL_SERVER_MESSAGE_STARTSIMULATION_H

#include <ros/service_traits.h>


#include <simulation_control_server/StartSimulationRequest.h>
#include <simulation_control_server/StartSimulationResponse.h>


namespace simulation_control_server
{

struct StartSimulation
{

typedef StartSimulationRequest Request;
typedef StartSimulationResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct StartSimulation
} // namespace simulation_control_server


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::simulation_control_server::StartSimulation > {
  static const char* value()
  {
    return "60bcc75747a184ebdba0e9c639470b9c";
  }

  static const char* value(const ::simulation_control_server::StartSimulation&) { return value(); }
};

template<>
struct DataType< ::simulation_control_server::StartSimulation > {
  static const char* value()
  {
    return "simulation_control_server/StartSimulation";
  }

  static const char* value(const ::simulation_control_server::StartSimulation&) { return value(); }
};


// service_traits::MD5Sum< ::simulation_control_server::StartSimulationRequest> should match 
// service_traits::MD5Sum< ::simulation_control_server::StartSimulation > 
template<>
struct MD5Sum< ::simulation_control_server::StartSimulationRequest>
{
  static const char* value()
  {
    return MD5Sum< ::simulation_control_server::StartSimulation >::value();
  }
  static const char* value(const ::simulation_control_server::StartSimulationRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulation_control_server::StartSimulationRequest> should match 
// service_traits::DataType< ::simulation_control_server::StartSimulation > 
template<>
struct DataType< ::simulation_control_server::StartSimulationRequest>
{
  static const char* value()
  {
    return DataType< ::simulation_control_server::StartSimulation >::value();
  }
  static const char* value(const ::simulation_control_server::StartSimulationRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::simulation_control_server::StartSimulationResponse> should match 
// service_traits::MD5Sum< ::simulation_control_server::StartSimulation > 
template<>
struct MD5Sum< ::simulation_control_server::StartSimulationResponse>
{
  static const char* value()
  {
    return MD5Sum< ::simulation_control_server::StartSimulation >::value();
  }
  static const char* value(const ::simulation_control_server::StartSimulationResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulation_control_server::StartSimulationResponse> should match 
// service_traits::DataType< ::simulation_control_server::StartSimulation > 
template<>
struct DataType< ::simulation_control_server::StartSimulationResponse>
{
  static const char* value()
  {
    return DataType< ::simulation_control_server::StartSimulation >::value();
  }
  static const char* value(const ::simulation_control_server::StartSimulationResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SIMULATION_CONTROL_SERVER_MESSAGE_STARTSIMULATION_H
