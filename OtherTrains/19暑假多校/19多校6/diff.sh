for((;;))
do
	./make > test0.txt
	./force < test0.txt > force.txt
	./1011 < test0.txt > 1011.txt
	if diff force.txt 1011.txt;then
		echo OK
	else
		echo !
		exit
	fi
done