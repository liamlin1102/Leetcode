class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1)>len(s2):
            return False
        dic={}
        dic2={}
        for index1 in range(len(s1)):
            if not s1[index1] in dic :
                dic[s1[index1]]=0
            dic[s1[index1]]+=1
        start = 0 ;end= len(s1)-1
        target = s2[start:end+1]
        for index2 in range(len(target)):
            if not target[index2] in dic2 :
                dic2[target[index2]]=0
            dic2[target[index2]]+=1
        if dic==dic2:
            return True
        for end in range(len(s1),len(s2)):
            if not s2[end] in dic2 :
                dic2[s2[end]]=0
            dic2[s2[end]]+=1
            dic2[s2[start]]-=1
            if dic2[s2[start]]==0:
                del dic2[s2[start]]
            if dic==dic2:
                return True
            start+=1
        return False














    # def checkInclusion(self, s1: str, s2: str) -> bool:
    #     if len(s1)>len(s2):
    #         return False
    #     dic ={}
    #     for index1 in range(len(s1)):
    #         if not s1[index1] in dic :
    #             dic[s1[index1]]=0
    #         dic[s1[index1]]+=1
    #     start=0
    #     for end in range(len(s1)-1,len(s2)):
    #         if s2[end] in dic :
    #             dic2 = {}
    #             target = s2[start:end+1]
    #             for index2 in range(len(target)):
    #                 if not target[index2] in dic2 :
    #                     dic2[target[index2]]=0
    #                 dic2[target[index2]]+=1
    #             if dic==dic2:
    #                 return True
    #         start+=1
    #     return False
        