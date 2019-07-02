for((;;))
do 
	./888 > test.txt
	./8 < test.txt > 1.txt
	./88 < test.txt > 2.txt
	if diff 1.txt 2.txt;then
		echo OK
	else
		echo !
		exit
	fi
done