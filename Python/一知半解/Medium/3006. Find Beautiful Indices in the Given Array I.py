from collections import deque
class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:
        if(len(a)>len(s)) or(len(b)>len(s)):
            return []
        aStr=deque(a)
        bStr = deque(b)

        alist=[]
        blist=[]
        answer=[]

        sStr = ""
        for i in range(len(a)):
            sStr +=s[i]
        sStr = deque(sStr)
        if(sStr==aStr):
            alist.append(0)

        for i in range(len(a),len(s)):
            sStr.popleft()
            sStr.append(s[i])
            if(sStr==aStr):
                alist.append(i-len(a)+1)
        sStr = ""
        for i in range(len(b)):
            sStr +=s[i]
        sStr = deque(sStr)
        if(sStr==bStr):
            blist.append(0)

        for i in range(len(b),len(s)):
            sStr.popleft()
            sStr.append(s[i])
            if(sStr==bStr):
                blist.append(i-len(b)+1)
        if(len(blist)==0) or (len(alist)==0):
            return []
        bIndex = 0
        dif = k+1
        diffIndex = -1
        for i in alist:
            while (bIndex<len(blist)) and (abs(i-blist[bIndex])>k):
                if(dif>abs(i-blist[bIndex])):
                    dif = abs(i-blist[bIndex])
                    diffIndex = bIndex
                bIndex+=1
            if(bIndex<len(blist)):
                answer.append(i)
            else:
                bIndex = diffIndex
        return answer