for((;;))
do
	./EEE > test.txt
	./E < test.txt > 1.txt
	./EE < test.txt > 11.txt
	if diff 1.txt 11.txt;then
		echo OK
	else
		echo !
		exit
	fi
done