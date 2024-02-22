class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        count = 1
        maxFre = 0
        dic={}
        for i in nums:
            if i not in dic :
                dic[i] = 0
            dic[i]+=1
            if(dic[i]==maxFre):
                count+=1
            elif (dic[i]>maxFre):
                count=1
                maxFre=dic[i]
        return maxFre*count