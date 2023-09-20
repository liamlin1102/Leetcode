class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        count=0
        for i in range(len(s)-2):
            if(s[i]!=s[i+1] and s[i]!=s[i+2] and s[i+1]!=s[i+2]):
                count+=1
        return count
    
class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        c,n=0,len(s)
        for i in range(n-2):
            t=set(s[i:i+3])
            if len(t)==3:
                c+=1
        return c