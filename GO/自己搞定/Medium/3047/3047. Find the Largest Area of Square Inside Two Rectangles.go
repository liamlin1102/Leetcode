func largestSquareArea(bottomLeft [][]int, topRight [][]int) int64 {
	var maxArea int64 = 0
	n := len(bottomLeft)

	for i := 0; i < n; i++ {
		left := bottomLeft[i][0]
		down := bottomLeft[i][1]
		right := topRight[i][0]
		top := topRight[i][1]

		for j := i + 1; j < n; j++ {
			left2 := bottomLeft[j][0]
			down2 := bottomLeft[j][1]
			right2 := topRight[j][0]
			top2 := topRight[j][1]

			// overlap width/height
			ow := minInt(right, right2) - maxInt(left, left2)
			oh := minInt(top, top2) - maxInt(down, down2)

			if ow <= 0 || oh <= 0 {
				continue
			}

			side := minInt(ow, oh)
			area := int64(side) * int64(side)
			if area > maxArea {
				maxArea = area
			}
		}
	}
	return maxArea
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}
