#!/bin/bash

rm -rf release debug
#rm -rf release/* debug/*

# make
mkdir release && cd release && cmake -DCMAKE_BUILD_TYPE=Release ../../src && make -j2 && cd ..
#mkdir debug && cd debug && cmake -DCMAKE_BUILD_TYPE=Debug ../../src && make  && cd ..

# make install.
#mkdir release && cd release && cmake -DCMAKE_BUILD_TYPE=Release ../../src && make install && cd ..
#mkdir debug && cd debug && cmake -DCMAKE_BUILD_TYPE=Debug ../../src && make install && cd ..
