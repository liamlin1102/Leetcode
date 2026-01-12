package main

//這題其實很麻煩，他其實做了壓縮跟很多事情，等等詳細解釋。
//首先，這題目的關鍵是，你要如何找到局部最大的方塊，會講局部是因為，0會切割方塊
//因此我們要透過Montonic stack 來把每一row 切割成不同的區域，並確認他們的大小
//由於合理性可能上下繼承，所以要先算高度，把高度累加成正確
//隨後我們的ms要放什麼? 我們要做一個increase montonicstack 他應該越來越大，因為代表我當前的邊可以無限包容當前的邊
//舉例，我 1 2 3 由於3>1 因此這個位置不用被清算，等到最後再被清算
//但假設，我遇到比我小的，是不是會導致我框入不合法的方塊，沒錯，因此一旦比當前top還小的數值或是0出現，都要處理
//我們一開始要先在stack插入一個 sentinel 因為我們蒜面積的方式是用，高度 * 左邊界+右邊界 -1
// 為什麼需要左右邊界?
// 因為就算我本身是一百，我有沒有可能是最高，導致一百只有自己吃的到
// 或是我本身是最低，其實整場都吃的到我(最低當然包含沒0)，因此定義，哪裡開始比我小，從自己當中心發散去找，很關鍵
// 由於存在左右真的一路到底，所以我們要在開頭插入一個0，-1，來讓我們不需要特別判斷，可以都使用看當前top當作左邊界的技術降低成本
// 而在最後避免走到底沒遇到0計算最終方塊，我們也要插入0手動更新

func maximalRectangle(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}
	height := len(matrix)
	stack := make([][]int, height)
	maxArea := 0
	once := 0

	for once < 1 {
		stack[0] = makeStackFirst(matrix[0])
		nowMaxArea := maxAreaFunc(stack[0])
		if nowMaxArea > maxArea {
			maxArea = nowMaxArea
		}
		once++
	}

	for indexH := 1; indexH < height; indexH++ {
		stack[indexH] = makeStack(matrix[indexH], stack[indexH-1])
		nowMaxArea := maxAreaFunc(stack[indexH])
		if nowMaxArea > maxArea {
			maxArea = nowMaxArea
		}
	}
	return maxArea
}

func maxAreaFunc(stack []int) int {
	montonicStack := make([]tuple, 0, len(stack))
	montonicStack = append(montonicStack, tuple{value: 0, index: -1}) //加入sentinel 讓我可以從頭到尾都用top來檢查左邊界的位置
	maxArea := 0
	for index := 0; index <= len(stack); index++ {
		nowHeight := 0
		if index < len(stack) {
			nowHeight = stack[index]
		}
		//第一個top
		top := montonicStack[len(montonicStack)-1]
		for nowHeight < top.value {
			//這就是pop
			montonicStack = montonicStack[:len(montonicStack)-1]
			//因為單調的關係，前一個一錠是他的左邊界
			leftTop := montonicStack[len(montonicStack)-1]
			nowArea := top.value * (index - leftTop.index - 1)
			if maxArea < nowArea {
				maxArea = nowArea
			}
			top = leftTop
		}
		montonicStack = append(montonicStack, tuple{value: nowHeight, index: index})
	}
	return maxArea
}

func makeStackFirst(data []byte) []int {
	stack := make([]int, len(data))
	for index, value := range data {
		stack[index] = int(value - '0')
	}
	return stack
}

func makeStack(data []byte, upData []int) []int {
	stack := make([]int, len(data))
	for index, value := range data {
		if value != '0' {
			stack[index] = upData[index] + 1
		} else {
			stack[index] = 0
		}
	}
	return stack
}

type tuple struct {
	value int
	index int
}
