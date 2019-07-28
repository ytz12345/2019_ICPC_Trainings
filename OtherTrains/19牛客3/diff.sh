for((;;))
do 
	./make > test.txt
	./D < test.txt > 1.txt
	python3 D.py < test.txt > 2.txt
	if diff 1.txt 2.txt;then
		echo OK
	else
		echo !
	fi
done