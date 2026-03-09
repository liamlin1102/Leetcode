class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        index = 0
        length = len(intervals)
        answer = []
        start,end = newInterval[0],newInterval[1]

        while index<length and intervals[index][1]<start:
            answer.append(intervals[index])
            index+=1

        while index<length and intervals[index][0]<=end:
            start = min(start,intervals[index][0])
            end = max(end,intervals[index][1])
            index+=1
        answer.append([start,end])
      
        while index<length :
            answer.append(intervals[index])
            index+=1
        return answer 
