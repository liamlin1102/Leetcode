# 這題反而很簡單，去找下一個比自己高的值
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack=[] ;ans = [0]*len(temperatures)
        # 一樣做Monotonic Stack，但這邊不一樣直接把找到的大值減去stack的index
        for index in range(len(temperatures)):
            while (stack) and (temperatures[stack[-1]]<temperatures[index]):
                # 當遇到比原本的大取出來，並且拿來跟現在的index比算距離
                popindex = stack.pop()
                ans[popindex] = index-popindex
            stack.append(index)
        return ans 