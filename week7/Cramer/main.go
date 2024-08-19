package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	dimenInp, _ := reader.ReadString('\r')
	dimensional, _ := strconv.Atoi(strings.TrimSpace(dimenInp))
	matrix := make([][]float64, dimensional)
	matrixX := make([]float64, dimensional)
	for i := range matrix {
		fmt.Printf("X[%d]: ", i+1)
		matrixXInp, _ := reader.ReadString('\r')
		matrixXInp = strings.TrimSpace(matrixXInp)
		matrixX[i], _ = strconv.ParseFloat(matrixXInp, 64)
		matrix[i] = make([]float64, dimensional)
	}

	for i := 0; i < dimensional; i++ {
		matrixInp, _ := reader.ReadString('\r')
		matrixInp = strings.TrimSpace(matrixInp)
		matrixInpV := strings.Split(matrixInp, " ")
		if len(matrixInpV) != dimensional {
			return
		}
		for j := 0; j < dimensional; j++ {
			matrix[i][j], _ = strconv.ParseFloat(matrixInpV[j], 64)
		}
	}
	determinantA := determinant(matrix)
	matrixTotal := make([]float64, dimensional)
	for i := 0; i < dimensional; i++ {
		matrixTemp := make([][]float64, dimensional)
		for j := 0; j < dimensional; j++ {
			matrixTemp[j] = make([]float64, dimensional)
			for k := 0; k < dimensional; k++ {
				matrixTemp[j][k] = matrix[j][k]
			}
		}
		for j := 0; j < dimensional; j++ {
			matrixTemp[j][i] = matrixX[j]
		}
		matrixTotal[i] = determinant(matrixTemp) / determinantA
		fmt.Printf("X[%d]: %.2f\n", i+1, matrixTotal[i])
	}
}

func determinant(matrix [][]float64) float64 {
	length := len(matrix)
	determinantUp := make([][]float64, length)
	determinantDown := make([][]float64, length)
	for i := 0; i < length; i++ {
		determinantUp[i] = make([]float64, length)
		determinantDown[i] = make([]float64, length)
		for j := 0; j < length-1; j++ {
			matrix[i] = append(matrix[i], matrix[i][j])
		}
	}
	for i := 0; i < length; i++ {
		for j := i; j < length+i; j++ {
			determinantUp[i][j-i] = matrix[i][j]
		}
		for j := (length - 1) + i; j <= length+1+i; j++ {
			determinantDown[i][(j-i-i)-(2-i)] = matrix[i][j-i-i]
		}
	}
	SumDeterminantUp := make([]float64, length)
	SumDeterminantDown := make([]float64, length)
	var SumDeterminantUpTotal float64 = 1
	var SumDeterminantDownTotal float64 = 1
	for i := 0; i < length; i++ {
		SumDeterminantUp[i] = 1
		SumDeterminantDown[i] = 1
		for j := 0; j < length; j++ {
			SumDeterminantUp[i] *= determinantUp[j][i]
			SumDeterminantDown[i] *= determinantDown[j][i]
		}
		SumDeterminantUpTotal += SumDeterminantUp[i]
		SumDeterminantDownTotal += SumDeterminantDown[i]
	}
	return SumDeterminantUpTotal - SumDeterminantDownTotal
}
