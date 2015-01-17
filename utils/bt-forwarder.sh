#!/bin/bash

rfcomm connect /dev/rfcomm0 $1 1 &
sleep 5
socat /dev/rfcomm0,raw,echo=0 tcp-connect:$2:$3
killall rfcomm

