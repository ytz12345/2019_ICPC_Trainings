for((;;))
do
	./AAA > test.txt
	./AA < test.txt > 1.txt
	./A < test.txt > 2.txt
	if diff 1.txt 2.txt;then
		echo OK
	else 
		echo !
		exit
	fi
done