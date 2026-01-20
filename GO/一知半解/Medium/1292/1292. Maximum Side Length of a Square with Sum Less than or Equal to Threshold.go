func maxSideLength(mat [][]int, threshold int) int {
	right := minInt(len(mat),len(mat[0]))
	left := 0

}

func makePrefixMatrix(mat [][]int) [][]int{
	height := len(mat)
	width := len(mat[0])
	prefixMatrix := make([][]int,height)
	for index := range prefixMatrix{
		prefixMatrix[index] = make([]int,width)

		topArea := 0 
		leftArea := 0
		overlapping :=0		
		nowNum :=0
		for index2 := range prefixMatrix[index]{
			nowNum = mat[index][index2]
			if index>0{
				topArea = prefixMatrix[index-1][index2]
			}

			if index2 >0{
				leftArea = prefixMatrix[index][index2-1]
			}

			if index ==0 && index2 ==0{
				overlapping = prefixMatrix[index-1][index2-1]
			}

			prefixMatrix[index][index2] =  nowNum+topArea+leftArea-overlapping
		}
	}
	return prefixMatrix
}
func minAreaArray( prefixMatrix [][]int, middeNum int,n int,m int )[][]int{
	minNum := math.MaxInt
	for i:= 0 ; i<shortLen-middeNum ; i++{
		for j:=0;j<shortLen-middeNum ; j++ {
			prefixMatrix[i+middeNum][j+middeNum]
			minNum = minInt(,minNum)
		}
	}
	return minNum
}

func makinprefixMatrix(mat [][]int,y int,x int, prefixMatrix [][]int) [][]int {
	
	//元素面積假設是從左上的資料推過來要有什麼，代表要有自己的元素+我上面以及左上那一塊的面積以及左邊。
	// 我用prefix sum來縮小工作量，因此我的上方必定是(0,0) to (x,y)
	// 所以就當然是(0,0) to (x-1,y-1) + (x,0) to (x,y-1) + (0,y) to (x-1,y) + (x,y)本身元素
	// 那是不是可以整理成(x,y)本身元素 + (0,0) to (x,y-1) + (0,0) to (x-1,y) - (0,0) to (x-1,y-1) (被重複計算一次)
	if y>0{
		topArea = prefixMatrix[y-1][x]
	}

	if x >0{
		leftArea = prefixMatrix[y][x-1]
	}

	if y ==0 && x ==0{
		overlapping = prefixMatrix[y-1][x-1]
	}
	
	prefixMatrix[y][x] =  mat[y][x]+topArea+leftArea-overlapping

	return prefixMatrix
}

func queryPrefixData(makinprefixMatrix [][]int,y int,x int) [][]int {
	//元素面積假設是從左上的資料推過來要有什麼，代表要有自己的元素+我上面以及左上那一塊的面積以及左邊。
	// 我用prefix sum來縮小工作量，因此我的上方必定是(0,0) to (x,y)
	// 所以就當然是(0,0) to (x-1,y-1) + (x,0) to (x,y-1) + (0,y) to (x-1,y) + (x,y)本身元素
	// 那是不是可以整理成(x,y)本身元素 + (0,0) to (x,y-1) + (0,0) to (x-1,y) - (0,0) to (x-1,y-1) (被重複計算一次)	
	if y>0{
		topArea = prefixMatrix[y-1][x]
	}

	if x >0{
		leftArea = prefixMatrix[y][x-1]
	}

	if y ==0 && x ==0{
		overlapping = prefixMatrix[y-1][x-1]
	}
	
	prefixMatrix[y][x] =  mat[y][x]+topArea+leftArea-overlapping

	return prefixMatrix
}


func countArea(prefixMatrix [][]int,y int,x int, topY int,leftX int ,diff int)int {
	// 這裡邏輯要反過來，如果我要算某個範圍內的面積
	// 我就要算 prefixMatrix[y+k][x+k] - prefixMatrix[topY-1][x] - prefixMatrix[y][leftX-1] +  prefixMatrix[topY-1][leftX-1]
	res := prefixMatrix [y+diff][x+diff]
	if y>0{
		res- = prefixMatrix[y-1][x]
	}

	if x >0{
		leftArea = prefixMatrix[y][x-1]
	}

	if y ==0 && x ==0{
		overlapping = prefixMatrix[y-1][x-1]
	}
	
	prefixMatrix[y][x] =  mat[y][x]+topArea+leftArea-overlapping

	return prefixMatrix
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
