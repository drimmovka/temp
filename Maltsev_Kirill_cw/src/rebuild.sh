#!/bin/bash

cd lib/EditorPNG; make clean
cd ../..; make clean
make build_lib
make