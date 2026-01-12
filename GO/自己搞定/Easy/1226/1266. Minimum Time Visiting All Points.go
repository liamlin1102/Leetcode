

func minTimeToVisitAllPoints(points [][]int) int {
	answer := 0
	for index := 1; index < len(points); index++ {
		yPath := points[index][0] - points[index-1][0]
		xPath := points[index][1] - points[index-1][1]
		absX := AbsInt(xPath)
		absY := AbsInt(yPath)
		maxNum := absY
		if absX > absY {
			maxNum = absX
		}
		answer += maxNum
	}
	return answer
}

func AbsInt(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

