import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if not s :
            return True
        s = re.sub("[\W_]","",s).lower()
        middle=int(len(s)/2)
        left = s[:middle]
        if len(s)%2!=0:           
            right = s[middle+1:]
        else:
            right = s[middle:]
        if left==right[::-1]:
            return True
        return False
