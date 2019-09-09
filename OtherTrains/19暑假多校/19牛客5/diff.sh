for((;;))
do
	./make > test.txt
	./C < test.txt > C.txt
	./CC < test.txt > CC.txt
	if diff C.txt CC.txt;then
		echo OK
	else
		echo !
		exit
	fi
done