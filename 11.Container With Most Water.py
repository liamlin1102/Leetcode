# 解題思路，會變得只有寬，讓左右往內靠找出最小的，因為容器只需要看最小的一邊，不需要管最大的那邊
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 設定邊界
        left = 0;right =len(height)-1;area=0;width=len(height)-1
        # 這題用寬去跑迴圈
        for wid in range(width,0,-1):
            # 如果右邊比較長，那我用左邊算最大面積，並且去跟之前的比
            if height[left]<height[right]:
                area = max(area,height[left]*wid)
                left +=1
            # 如果左邊比較長，那我用右邊去算最大面積，並且去跟之前的比
            else:
                area = max(area,height[right]*wid)
                right-=1
        return area 
