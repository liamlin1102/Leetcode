package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func subtreeWithAllDeepest(root *TreeNode) *TreeNode {

}

func recrusive(root *TreeNode, depth int) *TreeNode {
	if root == nil {
		return nil
	}
	depth++
	recrusive(root.Left, depth)
	recrusive(root.Right, depth)
	return

}
