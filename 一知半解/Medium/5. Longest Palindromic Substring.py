class Solution:
    # 找回文最基本就是用反向的two pointer，從中心擴散出去
    def longestPalindrome(self, s: str) -> str:
        # 只有他自己
        if len(s)==1:
            return s
        longestlength = 0;ans=""
        for index in range(len(s)-1):
            # 從一個當中心找最長
            curlength = self.LongLengthPalindromic(s,index,index)
            # 從兩個當中心找最長
            curlength2 = self.LongLengthPalindromic(s,index,index+1)
            if len(curlength2)>len(curlength):
                curlength = curlength2
            if len(curlength)>longestlength:
                longestlength = len(curlength)
                ans = curlength        
        return ans
    # 找最長回文的方法
    def LongLengthPalindromic(self,s,left,right):
        # 沒超過邊界同時他們是相等的
        while (left>=0 and right <len(s) and s[left]==s[right]):
                # 一個往左，一個往右
                left-=1
                right+=1
        # 回傳字串(記得left+1，right-1)
        return s[left+1:right]