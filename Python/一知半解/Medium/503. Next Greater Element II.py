# 這題考Monotonic Stack的進階，Monotonic Stack的原理就是要保持單線呈，有點像priority queue
# 很難，難道哭，下面詳解
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ## RC ##
        ## APPROACH : STACK ##
        ## Similar to leetcode 739. Daily Temperatures ##
        
        ## LOGIC ##
        ## 1. Monotone decreasing stack to find NGE (next greater element)
        ## 2. In the first loop, we fill NGE all possible.
        ## 3. In the second loop, there might be some elements left in the stack, so we iterate again (without appending to stack) and get NGE
        ## 4. The elements that are left in the stack even after second loop are max(nums).
        
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##
        # 看不懂英文我重複一 次，簡單說就是往右走，找下一個比自己大的數值，但nums呈現cricle，因此還要循環找，因此除了最大值之外都應該有數值，沒有的話呈現-1
        # 先定義變數
        stack, res = [], [-1] * len(nums)
        # 做第一次monotonic stack
        for i, num in enumerate(nums):              # 2
            # 檢查stack是否有東西，有的話去看前一個數值(nums[stack[-1]])是否比現在的小，是的話進去迴圈(我們要找比這個值大的)
            # 由於我們在stack裡面存入的是index ，因此正常狀況下他會存入前一個，但當你數字變小時，就不會進入迴圈因此會開始改變
            # ex:[1,6,4,3,2,5,2,1]
            # 第一次 由於stack是空的不進迴圈直接+ stack=[0],res = [-1,-1,-1,-1,-1,-1,-1,-1]
            # 第二次 因為6比1大把1排出去，stack = [1],res = [6,-1,-1,-1,-1,-1,-1,-1]
            # 第三次 因為4比6小，不進迴圈直接+，stack = [1,2] ,res = [6,-1,-1,-1,-1,-1,-1,-1]
            # 第四次 因為3比4，不進迴圈直接+，stack = [1,2,3] ,res = [6,-1,-1,-1,-1,-1,-1,-1]
            # 第五次 因為2比3，不進迴圈直接+，stack = [1,2,3,4] ,res = [6,-1,-1,-1,-1,-1,-1,-1]
            # 第六次 由於5比2、3、4都大，進迴圈把他們剔除並給值，stack = [1,5] ,res = [6,-1,5,5,5,-1,-1,-1]
            # 第七次 因為2比5小，因此不進迴圈直接+ stack = [1,5,6] ,res = [6,-1,5,5,5,-1,-1,-1]
            # 第八次 因為1比2小，因此不進迴圈直接+ stack = [1,5,6,7] ,res = [6,-1,5,5,5,-1,-1,-1]
            # 最後一個啥事都沒幹，這樣當然會出錯，因為cricle的題目定義應該長成， real_res = [6,-1,2,3,5,6,3,2]
            while stack and nums[stack[-1]] < num:
                res[stack.pop()] = num
            stack.append(i)
        # 因此我們要跑第二次，你可以視為我們將整個list延長了兩倍，這樣可以更清楚的處理問題
        for i, num in enumerate(nums):              # 3
            # 此時 stack = [1,5,6,7] ,  res = [6,-1,5,5,5,-1,-1,-1]
            # 這裡不一樣了現在的nums[stack[-1]]是誰，是1，從頭找有進迴圈現比他大的第一個值，當然就會是6，
            # 第二次 stack= [1,5,6]，6依然比2大
            # 第三次 stack = [1,5],6依然比5大
            # 第四次 跳出迴圈6跟6一樣大不進入，從此結束
            while stack and nums[stack[-1]] < num:
                res[stack.pop()] = num
        return res
# class Stack :
#     def __init__(self):
#         self.stack = []
#     def push(self,num):
#         self.stack.append(num)
#     def pop(self):
#         self.stack.pop(-1)
#     def top(self):
#         return self.stack[-1]
#     def empty(self):
#         return len(self.stack)==0
# class Solution:
#     def nextGreaterElements(self, nums: List[int]) -> List[int]:
#         stack = Stack();ans =[-1]*len(nums);nums += nums;
#         for index in range(len(nums)):
#             while (not stack.empty())and (nums[stack.top()]<nums[index]):
#                 if index>len(ans)-1:
#                     ans[stack.top()-len(ans)]=nums[index]
#                 else:
#                     ans[stack.top()]=nums[index]
#                 stack.pop()
#             stack.push(index)
#         return ans  

            
    