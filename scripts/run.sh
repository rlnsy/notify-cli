#!/bin/bash
DIV="------------------------->"
make clean
make
printf  "%s\n"      "$DIV"
./notify "$@"
printf  "\n%s\n"    "$DIV"
make clean
