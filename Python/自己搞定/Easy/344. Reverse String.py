class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # 反轉整個string 就從頭跟尾交換就好
        right,left = len(s)-1,0
        while right>left :
            s[right],s[left]=s[left],s[right]
            right-=1
            left+=1
        return s 