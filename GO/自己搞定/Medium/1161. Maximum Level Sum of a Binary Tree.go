
type TreeNode struct {
     Val int
     Left *TreeNode
     Right *TreeNode
}

func maxLevelSum(root *TreeNode) int {
	if root == nil {
		return 0
	}
	maxNum := root.Val
	nowNum := 0
    maxLevel := 1
    nowLevel := 2 

	levelTree := make([]*TreeNode, 0)
    if(root.Left !=nil){
        levelTree = append(levelTree,root.Left)
    }
    if(root.Right != nil){
        levelTree = append(levelTree,root.Right)
    }
	nowLevelTree := make([]*TreeNode, 0)

	for len(levelTree) > 0 {
		tree := levelTree[0]
		levelTree = levelTree[1:]
		nowNum+=tree.Val
		if tree.Left != nil{
			nowLevelTree = append(nowLevelTree,tree.Left)
		}
		if tree.Right != nil{
			nowLevelTree = append(nowLevelTree,tree.Right)
		}

		if(len(levelTree)==0){
			if nowNum > maxNum {
				maxNum = nowNum
                maxLevel = nowLevel
			} 
            levelTree = nowLevelTree
            nowLevelTree = make([]*TreeNode, 0)//大雷點，記得go的SLICE是 ptr len cap ，如果不用MAKE 改用 nowLevelTree = nowLevelTree[:0]，底層array不會被洗掉
			nowNum = 0 
            nowLevel++
		}
	}
	return maxLevel
}	