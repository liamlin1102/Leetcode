package main

import (
	"fmt"
	"sort"
)

func maximizeSquareHoleArea(n int, m int, hBars []int, vBars []int) int {
	maxN := 0
	maxM := 0
	shortL := n + 1
	if n > m {
		shortL = m + 1
	}
	maxN = findMaxNum(shortL, hBars)
	maxM = findMaxNum(shortL, vBars)
	minNum := maxN
	if maxM < maxN {
		minNum = maxM
	}
	return minNum * minNum
}

func findMaxNum(shortL int, bars []int) int {
	maxN := 0
	mapS := make(map[int][2]int)
	mapE := make(map[int][2]int)
	for _, value := range bars {
		if shortL <= maxN {
			return shortL
		}
		//四種狀況，你是頭，你是尾，你同時都是，你啥都不是
		nowS, containNS := mapS[value]
		nowE, containNE := mapE[value]

		previous := value - 1
		next := value + 1
		length := 0

		if containNS && containNE {
			fmt.Printf("input A")
			//同時都是，把頭跟尾拉到最長
			rightE := nowS[1]                                                                                    //你是起點的終點，就是最右
			leftS := nowE[1]                                                                                     // 你是終點的起點，就是最左
			length = max(mapS[value][0], mapE[mapS[value][1]][0]) + max(mapE[value][0], mapS[mapE[value][1]][0]) // 看誰最大，可能沒維護到
			// 展延
			tmpS := mapS[leftS]
			tmpS[0], tmpS[1] = length, rightE
			mapS[leftS] = tmpS

			tmpE := mapE[rightE]
			tmpE[0], tmpE[1] = length, leftS
			mapE[rightE] = tmpE
		} else if containNS {
			//自己是頭，修正我原來的尾，並新增一個頭
			rightE := nowS[1] //你是起點的終點，就是最右
			length += max(mapE[rightE][0], nowS[0]) + 1
			mapS[previous] = [2]int{length, rightE}
			tmpE := mapE[rightE]
			tmpE[0], tmpE[1] = length, previous //更新尾巴
			mapE[rightE] = tmpE
		} else if containNE {
			//自己是尾，修正我原來的頭，並新增一個尾
			leftS := nowE[1] //你是終點的起點，就是最左
			length += max(mapS[leftS][0], nowE[0]) + 1
			mapE[next] = [2]int{length, leftS} //新尾巴
			tmpS := mapS[leftS]
			tmpS[0], tmpS[1] = length, next //更新頭
			mapS[leftS] = tmpS
		} else {
			//都不是，代表我自己沒東西，單純更新前後就好
			mapS[previous] = [2]int{2, next} //新頭
			mapE[next] = [2]int{2, previous} //新尾
			length = 2
		}
		maxN = max(length, maxN)
	}
	return maxN
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// 我跟個傻逼一樣，這題目就排序，去找連續最長的子串數字回傳就好，又好比邊長+2，所以回傳+1 跟上面邏輯一樣
func maximizeSquareHoleArea(n int, m int, hBars []int, vBars []int) int {

	sort.Ints(hBars)
	sort.Ints(vBars)
	shortL := n + 1
	if n > m {
		shortL = m + 1
	}
	maxLenH := findMaxNum(hBars, shortL)
	maxLenV := findMaxNum(vBars, shortL)
	if maxLenH < maxLenV {
		return maxLenH * maxLenH
	}
	return maxLenV * maxLenV
}

func findMaxNum(hBars []int, shortL int) int {
	maxLenH := 1
	nowLen := 1
	hBars = append(hBars, 0)
	for index, value := range hBars {
		if shortL <= maxLenH {
			return shortL
		}
		if index == 0 {
			continue
		}
		if value-hBars[index-1] != 1 {
			maxLenH = max(maxLenH, nowLen)
			nowLen = 1
		} else {
			nowLen++
		}
	}
	return maxLenH + 1
}
