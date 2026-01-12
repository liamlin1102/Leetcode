package main
import "fmt"

// func minimumDeleteSum(s1 string, s2 string) int {
// 	s1AsArray := [26]int{}
// 	s2AsArray := [26]int{}
// 	const aAscCode = 97
// 	answer := 0 
// 	for _,value := range s1{
// 		s1AsArray[int(value)-aAscCode] ++
// 	}
// 	for _,value := range s2{
// 		s2AsArray[int(value)-aAscCode] ++
// 	}

// 	for index:=0;index<26;index++{
// 		s1Num := s1AsArray[index]
// 		s2Num := s2AsArray[index]
// 		ascCode := index+aAscCode
// 		if(s1Num==0 && s2Num!=0){
// 			answer+=(s2Num*(ascCode))
// 		}else if(s1Num!=0&&s2Num==0){
// 			answer+=(s1Num*(ascCode))
// 		}else{
// 			maxNum := s1Num
// 			minNum := s2Num
// 			if(s2Num>s1Num){
// 				maxNum =s2Num
// 				minNum = s1Num
// 			}	
// 			answer += ((maxNum-minNum)*ascCode)
// 		}
		
// 	}
// 	return answer 
// }

func minimumDeleteSum(s1 string, s2 string) int {
	dp := make([][]int, len(s1))
	for i := range dp {
		dp[i] = make([]int, len(s2))
	}
	//這題要用prefix dp，不然會卡四個小時....
	//base case
	if()
}

