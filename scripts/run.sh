#!/bin/bash
make clean
make
echo "------------------------->"
./notify
make clean
