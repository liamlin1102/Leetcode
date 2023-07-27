# 這題很難，但難在邏輯不難code
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums)==1:
            if target==nums[0]:
                return 0
            else:
                return -1
        # 跟一般的2項搜索一樣，但因為他是旋轉數列我們要先判斷哪裡是正常的
        left = 0;right = len(nums)-1
        # 與其去想哪邊反轉，導致規則改變，不如把正常的地方記下來然後其餘相反
        while left<=right:
            mid = left+(right-left)//2
            # 如果找到值，回傳回來
            if nums[mid]==target:return mid
            # 如果今天最右邊大於中間 
            elif nums[right]>nums[mid]:
                # 那麼正常狀況就應該右邊大於目標大於中間(物件在中間右方，因此移動左指針)
                if nums[right]>=target>nums[mid]:
                    left = mid+1
                # 其餘管他的，移動右指針就好
                else:
                    right = mid-1
            # 其他其況管他的
            else:
                # 把其他情況中唯一正常的，最左邊<=目標<中間值，此時移動右指針
                if nums[left]<=target<nums[mid]:
                    right = mid-1
                # 管他的，移動左指針
                else:
                    left = mid+1
        return -1 


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target in nums :
            return nums.index(target)
        else :
            return -1