#!/bin/bash

g++ -g shared_resource_allocation.cpp -o ra.out

for k in `seq 4 4`;
do
     	for n in `seq 1 60`;
	do	
		echo "k=$k,n=$n" >> R03_SoP.txt
		echo "k=$k,n=$n" >> R03_SoS.txt
		echo "k=$k,n=$n" >> R03_OR.txt

		for itr in `seq 1 10`;
		do	
			echo "k=$k,n=$n,iteration=$itr"	
			#sleep 1
			
			if [ $itr -eq 10 ]
			then
				sed -n "/^n=$n,iteration=10/,/^n=$(($n + 1)),iteration=1/p" R01_LoN.txt | awk '/^x/'|sed 's/;//g'|sed 's/x//g'|sed 's/ = / /g'|sed 's/\[//g'|sed 's/\]//g'>R01_x_n.txt
				sed -n "/^n=$n,iteration=10/,/^n=$(($n + 1)),iteration=1/p" R01_LoN.txt | awk '/^y/'|sed 's/;//g'|sed 's/y//g'|sed 's/ = / /g'|sed 's/\[//g'|sed 's/\]//g'>R01_y_n.txt

				sed -n "/^n=$n,iteration=10/,/^n=$(($n + 1)),iteration=1/p" R01_LoS.txt | awk '/^x/'|sed 's/;//g'|sed 's/x//g'|sed 's/ = / /g'|sed 's/\[//g'|sed 's/\]//g'>R01_x_s.txt
				sed -n "/^n=$n,iteration=10/,/^n=$(($n + 1)),iteration=1/p" R01_LoS.txt | awk '/^y/'|sed 's/;//g'|sed 's/y//g'|sed 's/ = / /g'|sed 's/\[//g'|sed 's/\]//g'>R01_y_s.txt
			else
				sed -n "/^n=$n,iteration=$itr$/,/^n=$n,iteration=$(($itr + 1))$/p" R01_LoN.txt | awk '/^x/'|sed 's/;//g'|sed 's/x//g'|sed 's/ = / /g'|sed 's/\[//g'|sed 's/\]//g'>R01_x_n.txt
				sed -n "/^n=$n,iteration=$itr$/,/^n=$n,iteration=$(($itr + 1))$/p" R01_LoN.txt | awk '/^y/'|sed 's/;//g'|sed 's/y//g'|sed 's/ = / /g'|sed 's/\[//g'|sed 's/\]//g'>R01_y_n.txt
				sed -n "/^n=$n,iteration=$itr$/,/^n=$n,iteration=$(($itr + 1))$/p" R01_LoS.txt | awk '/^x/'|sed 's/;//g'|sed 's/x//g'|sed 's/ = / /g'|sed 's/\[//g'|sed 's/\]//g'>R01_x_s.txt
				sed -n "/^n=$n,iteration=$itr$/,/^n=$n,iteration=$(($itr + 1))$/p" R01_LoS.txt | awk '/^y/'|sed 's/;//g'|sed 's/y//g'|sed 's/ = / /g'|sed 's/\[//g'|sed 's/\]//g'>R01_y_s.txt
			fi

			./ra.out $n $n $k

			rm R01_x_n.txt
			rm R01_y_n.txt
			rm R01_x_s.txt
			rm R01_y_s.txt
		done 
	done    
done 

rm ra.out
