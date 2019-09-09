for((;;))
do
	./111 > test.txt
	./1 < test.txt > 1.txt
	./11 < test.txt > 11.txt
	if diff 1.txt 11.txt;then
		echo OK
	else
		echo !
		exit
	fi
done