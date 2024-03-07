class Solution:
    def minimumPushes(self, word: str) -> int:
        length = len(word)
        if(length<=8):
            return length
        i = length//8
        m = length%8
        answer = 8*((i*(i+1))//2)
        answer= answer+m*(i + 1)
        return answer
            
            
        