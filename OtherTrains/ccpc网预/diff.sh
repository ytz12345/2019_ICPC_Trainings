for((;;))
do
	./make > test0.txt
	./8 < test.txt > 8.txt
	./88 < test.txt > 88.txt
	if diff 8.txt 88.txt;then
		echo OK
	else
		echo !
		exit
	fi
done