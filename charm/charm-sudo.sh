#!/bin/sh
sudo sysctl -w kernel.sched_rt_runtime_us=-1
sudo -E  $(dirname "$0")/charm $1