# 主要思路，要如何確保dic只有兩種水果，以及確定最長的長度
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        # 這邊我們使用了map，如果dic裡面超過了三種水果，我就開始從左邊刪除水果，並且維持到2個水果在往下走。只要記得，如果是左邊要連續判定往右走的狀態(像這題)就要用內部while
        left=0;maxlen = 0;dic={}
        for index in range(len(fruits)):
            if not fruits[index] in dic:
                dic[fruits[index]]=0
            dic[fruits[index]]+=1
            # 當我們發現內部長度超過了
            while len(dic)>2:
                # 開始扣水果
                dic[fruits[left]]-=1
                # 如果水果歸0那把它刪掉
                if dic[fruits[left]]==0:
                    del dic[fruits[left]]
                # 左指針往右走
                left+=1
            # 每次都檢查長度，由於是1比1，很快
            maxlen = max(maxlen,index-left+1)
        return  maxlen
    

from collections import defaultdict

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        count = defaultdict(int) # defaultdict to store the frequency of the elements in the subarray
        i, j = 0, 0 # variables i and j are used to keep track of the subarray boundaries
        for j in range(len(fruits)):
            count[fruits[j]] += 1 # increase the count of the current fruit
            if len(count) > 2: 
                count[fruits[i]] -= 1 # reduce the count of the first fruit
                if count[fruits[i]] == 0:
                    del count[fruits[i]] # remove the first fruit from the defaultdict if its count becomes 0
                i += 1 # move the start of the subarray to the right
        return j - i + 1 # return the length of the longest subarray with at most two unique elements