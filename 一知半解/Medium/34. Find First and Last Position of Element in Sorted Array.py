# 找邊界題目，這題剛好可以靈活二項搜尋的概念，上方為雙端都閉，下方為左閉右開
#以下為左閉右閉的概念
# 為什麼 r = arr.length - 1; 不能是r = arr.length嗎？ 因為我們使用的是左閉右閉，要考慮的index的範圍[0, 6]，所以l = 0, r = arr.size() - 1
# 為什麼 while條件式是 l <= r為執行條件，不能是l < r嗎？ 考慮l == r在左閉右閉上的情況，[3,3] -> 3 ，符合條件
# 為什麼是l = mid + 1, r = mid - 1？ 假設target = 19，mid = 3 => 11 假如mid不是答案，那mid排除在搜索範圍的區間裡，所以我們的區間就會變成 [mid + 1, right] 另一種情況 - 》[left, mid - 1]
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = 0;right=len(nums)-1;ans=[-1,-1]
        if not target in nums:
            return ans
        # 因為左閉右閉，我們要搜索的區間為[target start index,target end index]，因此相等還是要進迴圈跑一次確認他是邊界
        while (left<=right):
            mid = left+(right-left)//2
            # 確認左邊界的方法，確認邊界的方法口訣就是，你想找哪邊的邊界，就往那邊收束，因此只要找到符合target，就往那個方向移動
            # 由於這邊是找左邊界，因此我們只要在>=時重定義右指針，整體會往左跑
            if nums[mid]>=target:
                right = mid-1
            else:
                left = mid+1
        # 左邊界就要擺左邊，因為此時left>right
        ans[0]=left
        left2 = 0;right2=len(nums)-1
        while (left2<=right2):
            mid = left2+(right2-left2)//2
            # 確認右邊界的方法，確認邊界的方法口訣就是，你想找哪邊的邊界，就往那邊收束，因此只要找到符合target，就往那個方向移動
            # 由於這邊是找右邊界，因此我們只要在<=時重定義左指針，整體會往右跑
            if nums[mid]>target:
                right2 = mid-1
            else:
                left2 = mid+1
        # 右邊界就要擺右邊，因為此時left>right
        ans[1] = right2
        return ans
    
#以下為左閉右開的概念
# 為什麼 r = arr.length - 1; 不能是r = arr.length嗎？ 因為我們使用的是左閉右開，要考慮的index的範圍[0, 7)，所以l = 0, r = arr.size()
# 為什麼 while條件式是 l <= r為執行條件，不能是l < r嗎？ 考慮l == r在左閉右開上的情況，[3,3) -> {} ，不符合條件
# 為什麼是l = mid + 1, r = mid - 1？ 假設target = 19，mid = 3 => 11 假如mid不是答案，那mid排除在搜索範圍的區間裡，所以我們的區間就會變成 [mid + 1, right)==[mid+1,right+1] 另一種情況 - 》[left, mid)==[left,mid+1]
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = 0;right = len(nums);ans=[-1,-1]
        if not target in nums:
            return ans
        # 因為左閉右開，如果left==right，那代表是空集合，不需要再次進入檢查
        while (right>left):
            mid = left+(right-left)//2
            # 由於右開，因此mid不會-1
            if nums[mid]>=target:
                right = mid
            else:
            # 由於左閉，因此mid不會+1
                left=mid+1
        # 左邊直接擺left或right都行,這兩個相等
        ans[0] = left
        left2 = 0;right2 = len(nums)
        while (right2>left2):
            mid = left2+(right2-left2)//2
            if nums[mid]<=target:
                left2 = mid+1
            else:
                right2=mid
        # 右邊重要觀念，由於右邊在概念上是開，但我們的list是雙閉，因此直接擺left或right都行,這兩個相等，但是要-1，因為找出來的數值是mid+1，在右開的概念要還原成mid，因故要-1
        ans[1]=right2-1
        return ans