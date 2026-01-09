package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxProduct(root *TreeNode) int {
	const mod int64 = 1_000_000_007
	subNumList := []int64{}
	sumNum := recrusive(root, &subNumList)
	maxNum := int64(0)
	for _, num := range subNumList {
		nowNum := num * (sumNum - num)
		if nowNum > maxNum {
			maxNum = nowNum
		}
	}
	return int(maxNum % mod)

}

func recrusive(root *TreeNode, subNumList *[]int64) int64 {
	if root == nil {
		return 0
	}
	leftValue := recrusive(root.Left, subNumList)
	rightValue := recrusive(root.Right, subNumList)
	sumNum := leftValue + rightValue + int64(root.Val)
	*subNumList = append(*subNumList, sumNum)
	return sumNum
}
