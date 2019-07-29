for((;;))
do
	./make > test.txt
	./force < test.txt > force.txt
	./1008 < test.txt > 1008.txt
	if diff force.txt 1008.txt;then
		echo OK
	else
		echo !
		exit
	fi
done