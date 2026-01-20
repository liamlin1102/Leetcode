func minBitwiseArray(nums []int) []int {
	//這題蠻簡單，找連續的1，如果從頭到尾都是1，就直接右移1格，因為可以一路進位到最高
	// 如果長度只有1，代表是2，要返回
	answer := make([]int, len(nums))
	for index, num := range nums {
		length, continous, allOne := checkNumsBit(num)
		if length == 0 {
			answer[index] = -1
		} else if allOne {
			answer[index] = num >> 1
		} else {
			answer[index] = num - (1 << continous) //把對應的位置1刪掉，只留右邊的1，這樣+1就能進位達到OR的答案
		}
	}
	return answer
}

func checkNumsBit(num int) (int, int, bool) {
	continous := 0
	length := 0
	for num&1 == 1 {
		length++
		continous++
		num = num >> 1
	}
	return length, continous, num == 0

}