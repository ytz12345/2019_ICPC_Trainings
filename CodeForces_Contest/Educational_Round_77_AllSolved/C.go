package main

import (
	"fmt"
	"os"
)

func gcd(x, y int64) int64 {
	if y == 0 {
		return x
	} else {
		return gcd(y, x%y)
	}
}

func main() {
	var n int
	fmt.Fscanln(os.Stdin, &n)
	for i := 0; i < n; i++ {
		var a, b, c int64
		fmt.Fscanln(os.Stdin, &a, &b, &c)
		if a < b {
			a, b = b, a
		}
		//fmt.Println(a, b, c, gcd(a, b))
		if a == b || gcd(a, b)+(c-1)*b >= a {
			fmt.Println("OBEY")
		} else {
			fmt.Println(("REBEL"))
		}
	}
}
