class Solution:
    def areaOfMaxDiagonal(self, dimensions):
        maxLen=0
        answer = 0
        nowLen = 0
        for i in range(len(dimensions)):
            nowLen = (dimensions[i][0]**2+dimensions[i][1]**2)**0.5
            if(nowLen>maxLen):
                answer = dimensions[i][0]*dimensions[i][1]
                maxLen = nowLen
            elif(nowLen==maxLen):
                answer = max(dimensions[i][0]*dimensions[i][1],answer)
        return answer