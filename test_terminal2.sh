#!/bin/bash

echo -e "\E[H\E[J"

echo -e "\E(0"
echo -n -e "\E[10;5H"

echo "lqqqqqqk"
y=10
for i in {1..6}; do
((y = y + 1));
echo -n -e "\E[$y;5H"
  echo "x      x"
done
((y = y +1))
echo -n -e "\E[$y;5H"
echo "mqqqqqqj"

echo -n -e "\E[11;1H"
echo -e "\E[5aaaaaaa"
echo -e "\E[5aaa"
echo -e "\E[5aaa"
echo -e "\E[5aaaaaaa"
echo -e "\E[9aaa"
echo -e "\E[5aaaaaaa"
echo -n -e "\E[20;1H"
printf "\E(B"
