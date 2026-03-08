class Solution:
    def numDecodings(self, s: str) -> int:
        if(s[0] == "0"):
            return 0
        prev = 1
        beforeTwo = 1
        for index in range(1,len(s)):
            nowCount = 0
            if s[index] !="0":
                nowCount+=prev
            if  s[index-1]!="0" and int(s[index-1]+s[index])<27:
                nowCount+=beforeTwo
            beforeTwo = prev
            prev = nowCount
        return prev 
