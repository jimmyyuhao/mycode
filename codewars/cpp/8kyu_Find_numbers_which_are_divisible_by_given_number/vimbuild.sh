#!/bin/bash
echo $(pwd)
cd $(pwd)
rm $(pwd)/main
g++ -Wall -g -v -o2 -std=c++11 ./main.cpp -pthread -lm -lcrypto -ldl -o2 -I g:VIM_FILEDIR/include -o main
chmod +x $(pwd)/main
$(pwd)/main
