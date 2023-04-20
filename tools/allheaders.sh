#!/bin/bash

path=../include/

echo "g++ Tensor.h"
echo $(g++ ${path}Tensor.h)

echo "g++ Indexing.h"
echo $(g++ ${path}Indexing.h)

echo "g++ Reshaping.h"
echo $(g++ ${path}Reshaping.h)
