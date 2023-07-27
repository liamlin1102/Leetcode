class Solution:
    def threeSum(self, nums):
        res = []
        nums.sort()
        # 由於需要三個數字，用two pointer會少一個 所以一定要先跑一次Loop
        for i in range(len(nums)-2):
            # 由於排序過，只要當下的數字跟前一個一樣，就跳過以免重複
            if i > 0 and nums[i] == nums[i-1]:
                continue
            # 左右抓好
            l, r = i+1, len(nums)-1
            # Two pointer
            while l < r:
                # 三個值有沒有等於0
                s = nums[i] + nums[l] + nums[r]
                # 如果小就往右加
                if s < 0:
                    l +=1
                # 如果大就往左減 
                elif s > 0:
                    r -= 1
                # 等於0加起來
                else:
                    res.append((nums[i], nums[l], nums[r]))
                    #需符合two-pointer條件，並且如果下一個數字一樣我就往後加避免重複 
                    while l < r and nums[l] == nums[l+1]:
                        l += 1
                    while l < r and nums[r] == nums[r-1]:
                        r -= 1
                    l += 1; r -= 1
        return res