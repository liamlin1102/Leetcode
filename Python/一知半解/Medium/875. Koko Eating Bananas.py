import math 
# 解題思路，猴子可以把剩餘的吃掉如果大於的話，因此就拿吃的數量去除

class Solution:
    def minEatingSpeed(self, A, h):
        # 由於我們不知道猴子會吃幾個因此最少要吃一根最多就最大值不然吃不完
        l, r = 1, max(A)
        # 當最少比最多小時
        # 加1的原理是因為我們是打算收斂整個函數找到最佳解，由於我們是使用lower mid，因此要把最小值+1，並且把條件設定成high>low
        while l < r:
            # 算中間值
            mid = (l + r) // 2
            # 如果警衛離開的小時數量，小於吃的小時數，代表吃太少了要多一點，因此調整最小值到中間值+1，ceil是無條件進位，因為不論餘數多少都要再吃
            if h < sum(ceil(a / mid) for a in A): l = mid + 1
            else: r = mid
        return l


    # def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # maxbananas = self.findmax(piles)
        # minbananas = 1
        # while maxbananas>minbananas:
        #     mid  = (maxbananas+minbananas)//2
        #     _h = 0
        #     for pile in piles:
        #         _h += math.ceil(pile/mid)
        #     if _h>h:
        #         minbananas=mid+1
        #     else :
        #         maxbananas=mid
        # return minbananas
            
            
    def findmax(self,nums):
        if len(nums)==2:
            return max(nums[0],nums[1])
        if len(nums)==1:
            return nums[0]
        left = 0;right = len(nums)
        mid =(right-left)//2
        leftmax = self.findmax(nums[:mid])
        rightmax = self.findmax(nums[mid:])
        if leftmax>rightmax:
            return leftmax
        else:
            return rightmax