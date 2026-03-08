class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        queue = []

        for pair in prerequisites:
            indegree[pair[0]]+=1
            graph[pair[1]].append(pair[0])

        for index,value  in enumerate(indegree):
            if value == 0:
                queue.append(index)
    
        count = 0
        while len(queue) != 0:
            count +=1
            course = queue.pop(-1)
            for value in graph[course]:
                indegree[value]-=1
                if indegree[value] == 0 :
                    queue.append(value)
        return count == numCourses