
class Solution:
    def maximumLength(self, s: str) -> int:
        lenS = len(s)
        answer = 0
        setNum = set()
        lWord= ""
        lWordLen = 0
        for i in range(lenS):
            count = i
            while(count<lenS):
                if(lWord!="" and lWord[-1]!=s[count]):
                    break
                lWord += s[count]
                lWordLen+=1
                count+=1
            setNum.add(lWord)
            lWord=""
            lWordLen=0
        count = 0
        maxLen = 0
        for i in setNum:
            queue = []
            queueS = []
            for ii in i:
                queue.append(ii)       
            for j in s:
                queueS.append(j)
                if(len(queueS)>len(queue)):
                    queueS.pop(0)
                if(queueS == queue):
                    count+=1
                if count>=3:
                    maxLen = (max(maxLen,len(queue)))
                    break
            count = 0

        return maxLen if maxLen!=0  else -1