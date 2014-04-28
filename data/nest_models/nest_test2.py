#! /usr/bin/env python

# Test for the adapting exponential integrate and fire model according to
# Brette and Gerstner (2005) J. Neurophysiology.
# This script reproduces figure 3.d of the paper.
# Note that Brette&Gerstner give the value for b in nA.
# To be consistent with the other parameters in the equations, b must be
# converted to pA (pico Ampere).

import nest
import nest.voltage_trace
import voltage_trace_ros

voltage_trace_ros.init()

nest.ResetKernel()
res=0.1
nest.SetStatus([0],[{"resolution": res, "overwrite_files": True}])
neuron=nest.Create("aeif_cond_alpha")
nest.SetStatus(neuron,[{"V_peak": 0.0, "E_L":-60.0, "a":80.0, "b":80.5, "tau_w": 720.0}])
dc=nest.Create("dc_generator")

nest.SetStatus(dc,[{"amplitude":-800.0, "start":0.0, "stop":400.0}])

nest.ConvergentConnect(dc,neuron)

voltmeter= nest.Create("voltmeter")
nest.SetStatus(voltmeter,[{"to_file": True, "withtime": True}])
nest.Connect(voltmeter,neuron)

nest.Simulate(1000.0)

voltage_trace_ros.from_device(voltmeter)
#nest.voltage_trace.show()
