# 解題思路，這題要找最長的嚴格遞增sublist的長度，因此要做的事情挺複雜的。
# 我們預計讓dp srore 原nums[index]當結尾時的嚴格遞增的長度。很凹口對吧，我用題目講解ㄖ

# 此方法的DP更新，該DP的定義為，dp[i]= 以nums[i]結尾最長的值
# EX [10,11,2],dp= [1,2,1],此時的nums[2]雖然是1，他的意思不是只到nums[i]最長長度，而是以nums[i]為結尾最長的值
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 就算完全沒有遞增，長度也有1默認給1
        dp=[1]*len(nums)
        # 先跑整個長度，因為我們是否會更新長度取決新來的數字是否有比中間任何一個值小，有的話就要看看長度是否會更新
        for index in range(len(nums)):
            # 從頭跑並且跟nums[index]比較
            for sindex in range(index):
                # 如果任何一個值比新來的朋友小
                if nums[index]>nums[sindex]:
                    # 我們就要檢查在這個index的時候長度是否變多，舉個例子
                    # 有nums = [1,6,2,10]，此時dp=[1,1,1,1] 
                    # 跑第二次.6>1,因此會比較 dp[1] or dp[0]+1,dp[1]此刻沒值是1 dp[0]+1是2 ，此時dp[1]會更變成2 dp=[1,2,1,1]
                    # 跑第三次,2>1 因此會比較 dp[2] or dp[0]+1,dp[2]此刻沒值是1 dp[0]+1是2 ，此時dp[2]會更變成2 dp=[1,2,2,1]
                    # 跑第四次,10>1 因此會比較 dp[3] or dp[0]+1,dp[3]此刻沒值是1 dp[0]+1是2 ，此時dp[3]會更變成2 dp=[1,2,2,2] 
                    #  10>6  因此會比較 dp[3] or dp[1]+1,dp[3]此刻值是2 dp[1]+1是3 ，此時dp[3]會更變成3 dp=[1,2,2,3]  
                    dp[index] = max(dp[index],dp[sindex]+1)
        return max(dp)

# 這邊使用另一種方法來加快排序，要注意，這種排序法排出來的list會打亂順序
# 使用Binary search 來排序，我們將nums放進dp當第一個值，然後如果在後續nums往下走，如果比dp[0]小,取代dp[0],如果比dp[-1]大,則往後加一個(不是取代)，如果介於中間，那就用binary shearch找出最不小於他的值(>=)
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp=[nums[0]]
        for num in (nums[1:]):
            # 如上面說的,如果比dp[0]小,取代dp[0],如果比dp[-1]大,則往後加一個(不是取代)
            if num<dp[0]:
                dp[0]=num
            elif num>dp[-1]:
                dp.append(num)
            # 用BS 確定最不小於她的值的位置後取代他
            else:
                left =0;right=len(dp)-1
                while right>left:
                    mid = left+(right-left)//2
                    if dp[mid]<num:
                        left = mid+1
                    else:
                        right = mid
                dp[left] = num
        return len(dp)

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp=[nums[0]]
        # 往後看
        for num in (nums[1:]):
            if num>dp[-1]:
                dp.append(num)
            else:
                left =0;right=len(dp)-1
                while right>left:
                    mid = left+(right-left)//2
                    if dp[mid]<num:
                        left = mid+1
                    else:
                        right = mid
                dp[left] = num
        return len(dp)



