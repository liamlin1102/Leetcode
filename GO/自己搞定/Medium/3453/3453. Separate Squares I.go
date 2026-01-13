func separateSquares(squares [][]int) float64 {
	const issue float64 = 0.00001
	minY := squares[0][1]
	maxY := squares[0][1]
	areaTable := make([]float64, len(squares))
	for index, cordinates := range squares {
		nowY := cordinates[1]
		height := cordinates[2]
		if nowY+height > maxY {
			maxY = nowY + height
		}
		if nowY < minY {
			minY = nowY
		}
		areaTable[index] = float64(cordinates[2] * cordinates[2])
	}
	right := float64(maxY)
	left := float64(minY)
	for right-left >= issue {
		topArea := float64(0)
		downArea := float64(0)
		middleY := left + (right-left)/2
		for index, cordinates := range squares {
			nowY := float64(cordinates[1])
			height := float64(cordinates[2])
			if nowY >= middleY {
				topArea += areaTable[index]
			} else {
				//沒被突破，整個在下
				if nowY+height <= middleY {
					downArea += areaTable[index]
				} else {
					//被突破，要扣掉突破的加回上面
					// middleY - nowY 等於下半的長
					// nowY + height- middleY 等於上半的長
					overY := nowY + height - middleY
					downArea += height * (middleY - nowY)
					topArea += height * overY
				}
			}
		}
		//如果上面比較小，代表我的Y要往下，讓他可以變大，同時，如果相等，也要確保找到最小值的答案，只要有進來就是高於誤差
		if topArea <= downArea {
			right = middleY
		} else {
			left = middleY
		}
	}
	return right
}