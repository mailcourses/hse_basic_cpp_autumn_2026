#! /usr/bin/env bash

set -o errexit
set -o nounset
set -o xtrace

python3 generate_grades.py > grades.txt
g++ -std=c++20 grades.cpp -o grades
./grades
