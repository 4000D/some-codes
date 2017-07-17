#!/bin/bash
g++ ./main.cpp -o main
./main < tc.in > my.out

result=$(diff my.out tc.out)

if [[ ! "$result" ]]; then
  echo "success"
else
  diff my.out tc.out
fi
