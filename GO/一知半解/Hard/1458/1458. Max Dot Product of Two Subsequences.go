package main

import "fmt"

/* 這一題的關鍵是他不能回頭，必須是子序列。 因此，我們要在兩個array找出兩個隨機長度的子序列 此時，
為了避免窮舉導致複雜度爆炸，我們要用DP
能用DP的關鍵就是 1.他順序是固定，因此不會有莫名回頭的問題，讓題目可以把過去的狀態壓縮
2.他本身有固定規律，因為中間的狀態可以被傳承 我詳細解釋我的認知。
首先，我們的DP(nums1Index,nums2Index) 他在對應的Dp(I,j)位置的定義是， 在只允許使用 nums1 的前 i 個、nums2 的前 j 個元素時，能得到的最大「非空子序列點積」
 這時候會有一個迷思，你會以為每個點都是到達那個位值的最大值。 但其實不全然，他是指，在那個位置，能達到的子序列最大值。
 接下來有四個狀態
  A 我沒打算使用當前的元素
  A-1 我去找隨便一個nums[i-n][j]的累積最大值，因為我不使用當前元素，那我就要去找以外的範圍最大值，由於我們會一路把數值堆疊到最上方（同Y軸），找nums[i-1][j]即可
  A-2 同理，只是XY相反
  B我要使用這個數字，這個數字有兩個狀況
  B-1 我要使用這個數字當開頭
  B-2我要把這個數字接在前面最大的值上方
  因此我只要在這四個值找最大值，接下來數字就會被妥善分配，因此，我只要一直重複這麼做，我就可以找出到每一個點的總計最大值。
  所以關鍵就是，我可能在2,5的值 他是直接使用1,5範圍的值，因為那裏就是這個範圍最大的值也說不訂(代表這數字會是負的)。
  同時，但我必須要把值往下傳，這樣我要找2,5的人就會知道，喔，我直接拿這個最大的值就好。
  當然，這個方法會失去指向性，我會不知道這個值到底是誰給的，但我可以保證在每一個點，他都是累積到這個位置最大值
*/

func max(vals ...int) int {
	m := vals[0]
	for _, v := range vals {
		if v > m {
			m = v
		}
	}
	return m
}

func maxDotProduct(nums1 []int, nums2 []int) int {
	// productMatrix  := [][]int{{}}
	dp := make([][]int, len(nums1))
	for i := range dp {
		dp[i] = make([]int, len(nums2))
	}
	for index, value := range nums1 {
		for index2, value2 := range nums2 {
			dontUseIndexValue := 0
			dontUseIndex2Value := 0
			useHereForFinal := 0
			nowValue := value * value2
			maxNum := nowValue
			if index > 0 {
				dontUseIndexValue = dp[index-1][index2]
				maxNum = max(dontUseIndexValue, maxNum)
			}
			if index2 > 0 {
				dontUseIndex2Value = dp[index][index2-1]
				maxNum = max(dontUseIndex2Value, maxNum)
			}
			if index > 0 && index2 > 0 {
				useHereForFinal = dp[index-1][index2-1]
				maxNum = max(nowValue+useHereForFinal, maxNum)
			}
			dp[index][index2] = maxNum

			// productMatrix[index][index2] = value * value2
		}
	}
	return dp[len(nums1)-1][len(nums2)-1]

}

func main() {
	nums1 := []int{1, 2, 3}
	nums2 := []int{4, 5, 6}
	fmt.Printf("%d", maxDotProduct(nums1, nums2))
}
