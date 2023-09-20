# 兩種解題思路方法基本上一樣差在重建最小子結構，子結構有兩種思路
# 此為思路1，[m1,m2,m3]最大的錢要馬是m3+m1 or m2 因此就是每個都檢查 他本體-2+他本體 或是本體-1
# 兩邊共同觀念，只有一個不用比，兩個就那兩個看就好，該方法是找出是找出每個i結尾的可能的最大值
class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0] * len(nums)

        for i in range(len(nums)):
            if i == 0:
                dp[0] = nums[0]
            elif i == 1:
                dp[1] = max(nums[0], nums[1])
            else:
                # 此為思路1，[m1,m2,m3]最大的偷竊要馬是m3+m1 or m2 因此就是每個都檢查 他本體-2+他本體 或是本體-1
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
                # 由於是找出每個sublist可能的最大值，因此回傳這個就好
        return dp[-1]

# 此為思路2，[m1,m2,m3,m4] m4最大的要馬是 m3+m4 要馬是m2+m4，用相加法，由於前三個無法用公式算，手動填值
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        elif len(nums)==2:
            return max(nums[0],nums[1])
        elif len(nums)==3:
            return max(nums[0]+nums[2],nums[1])
        dp=[0]*len(nums)  
        dp[0] = nums[0];dp[1]=nums[1];dp[2] = nums[0]+nums[2]
        for index in range(3,len(nums)):
            dp[index] = nums[index]+max(dp[index-2],dp[index-3])
        # 由於是計算每個點的最大值，所以要檢查倒數第二跟第一
        return max(dp[-1],dp[-2])