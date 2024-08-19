package main

import (
	"fmt"
	"math"
)

func g(x float64) float64 {
	return 0.5 * (x + (1200 / x))
}

func main() {
	var xo float64 = 1
	var xn float64 = 0
	for i := 0; math.Abs(xn-g(xo)) > 0.000001; {
		i++
		xn = g(xo)
		fmt.Printf("%d : %.6f\n", i, xn)
		xo = xn
	}
}
