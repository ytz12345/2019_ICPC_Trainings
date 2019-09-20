for((;;))
do
	./DDD > test.txt
	./D < test.txt > 1.txt
	./DD < test.txt > 11.txt
	if diff 1.txt 11.txt;then
		echo YesYes
	else
		echo !
		exit
	fi
done