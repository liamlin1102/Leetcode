class Solution:
    def minimumPushes(self, word: str) -> int:
        ascList = [0]*26
        for w in word:
            ascList[ord(w)-ord("a")]+=1
        ascList=sorted(ascList,reverse=True)
        answer = 0
        count=0
        for i in range(26):
            if(ascList[i]==0):
                break
            if(i%8==0):
                count+=1
            answer+=ascList[i]*count  
        return answer