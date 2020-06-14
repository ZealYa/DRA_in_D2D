#!/bin/bash

g++ -g node_generator_v01.cpp -o ng.out
#g++ -g node_generator_v02.cpp -o ng.out
#g++ -g node_generator_v03.cpp -o ng.out

for n in `seq 60 60`;
do	
	for itr in `seq 1 10`;
	do	
		echo "n=$n,iteration=$itr"
		echo "n=$n,iteration=$itr" >> R01_LoN.txt
		echo "n=$n,iteration=$itr" >> R01_LoS.txt
		echo "n=$n,iteration=$itr" >> R02_NN.txt
		./ng.out $n	
		sleep 1
	done 
done

