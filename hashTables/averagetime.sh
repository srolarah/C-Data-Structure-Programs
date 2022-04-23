#!/bin/bash
echo "enter the exponent for counter.cpp:"
dict="$input1"
times=1
sum=0
averageTime=0
for (( i=0; i<=4; i++)) ; do
    echo "Running iteration $times..."
    TIME_1=`./a.out $dict | tail -1`
    echo "time taken: $TIME_1 ms"
    ((sum=$sum+$TIME_1))
    if [ $times -eq 5 ] ; then
	echo "$times iterations took $sum ms"
    else
	((n=$n+1))
    fi
done
((averageTime=$sum/5))
echo "Average time was $averageTime ms"
