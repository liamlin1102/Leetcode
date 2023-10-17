# 絲路:不需要管長的那邊多長，只要管短的那邊，並且不斷記錄左右各自的最大值，只要左邊比右邊小，並且目前的左邊是否為最大的左邊，如果是就用最大值-數字就是水位
class Solution:
    def trap(self, height: List[int]) -> int:
        # 由於題目給的條件，左右最大先訂為0
        left = 0;right = len(height)-1;water = 0;max_left=0;max_right=0
        # 當左邊不大於右邊，由於是要算幾格水，所以兩指針要指回同一點不然會漏算
        while left<=right:
            # 當右邊比較大，代表今天左邊是短編，因此先把左邊的最大值比較，如果目前短邊大於原先左邊的最大值，用短邊計算，否則用左邊的最大值
            if height[left]<height[right]:
                # 確定誰比較大
                max_left = max(max_left,height[left])
                # 扣掉自身就知道多少水
                water += max_left-height[left]
                left+=1
            else :
            # 當左邊比較大，代表今天右邊是短邊，因此先把右邊的最大值算出來，如果目前短邊大於原先右邊的最大值，用短邊計算，否則用右邊的最大值
                max_right = max(max_right,height[right])
                water += max_right-height[right]
                right -= 1
        return water 
