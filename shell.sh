i=1
while [ $i -le 100 ]
do
    echo $i
    i=$(expr $i + 1)
done


#!/bin/bash
echo "enter number"
read n
fact=1
for ((i=1;i<=$n;i++))
do
fact=$((fact*i))
done
echo " The factorial is $fact"


#!/bin/bash
read -p "Enter a number: " num
sum=0
while [ $num -gt 0 ]
do
  sum=$((num % 10 + sum)) 
  num=$((num / 10))    
done
echo Sum of digits is $sum.
