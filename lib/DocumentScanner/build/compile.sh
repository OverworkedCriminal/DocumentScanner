#!/bin/bash

workspace="../"

echo "compiling..."
g++ -O2 -c -Wall -I "$workspace/include" -I "/usr/include/opencv4" -l:libopencv_core.so -l:libopencv_imgproc.so -l:libopencv_imgcodecs.so $workspace/*.cpp $workspace/preprocessing/*.cpp $workspace/corners_finding/*.cpp
echo "packing..."
ar rvs libdocumentscanner.a *.o
echo "removing leftovers..."
rm *.o