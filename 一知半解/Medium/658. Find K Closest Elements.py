# 這題也有點難，基本上就是有三個方法，two pointer/binary seartch/混合用

# binary search 
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # 右指針定在右邊數來第k個，原因下面解釋
        left, right = 0, len(arr) - k
        # 由於我們是找節點的開頭，開頭要符合什麼條件，從開頭往右數，必須要後續數列跟x的絕對值最小，因此只要
        while left < right:            
            mid = (left + right) // 2
            # 如果我發現，中點的數字跟目標的絕對值，是大於右邊K個數減掉絕對值，代表左邊的這一個數字更更大，移動左邊的數字找接近右邊的中點
            if abs(arr[mid] - x) > abs(arr[mid + k]  - x):
                left = mid + 1
                # if All duplicate and the first one is large than x
            # arr[mid] < x need to filter out this kind of case: [1,1,2,2,2,2,2,2,2,2] 3 1
            # 如果終點跟他相等，但終點的數字是比她小的(代表左右的差額一樣但是我們定義一樣的話左邊是比較符合條件的)
            elif arr[mid] == arr[mid + k] and arr[mid] < x:
                left = mid + 1
            else:
                right = mid
            
        return arr[left: left + k]

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        right = self.getClosetNumber(arr, x)
        left = right - 1
        for _ in range(k):
            if self.getLeftCloserNumber(arr, left, right, x) == right:
                right += 1
            else:
                left -= 1
        left = 0 if right - k < 0 else right - k
        print(left, right)
        return arr[left:] if left == right else arr[left:right]
            
        
        
    def getClosetNumber(self, nums, target):
        left, right = 0, len(nums) - 1
        
        while left + 1 < right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid
            else:
                right = mid
        
        return self.getLeftCloserNumber(nums, left, right, target)
    
    def getLeftCloserNumber(self, nums, left, right, target):
        if left < 0:
            return right
        if right > len(nums) - 1:
            return left
        return left if abs(nums[left] - target) <= abs(nums[right] - target) else right

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        left = 0 ;right =len(arr)-1;mid=0;ans =[];midind=-1
        if k>=len(arr):return arr
        while (right>=left):
            mid = left+(right-left)//2
            if arr[mid]<=x:        
                left =mid+1
            else:
                right= mid-1
        #找右邊界會落在比目標x小的最後一個數字
        #找左逼界會落在比目標x大的第一個數字
        if right<len(arr)-1 and abs(arr[right]-x)>abs(arr[right+1]-x):keyindex = right+1
        else:keyindex=right
        
        if keyindex<=0  :return arr[:k]
        elif keyindex==len(arr)-1:return arr[-k:]

        chekleft = keyindex-1;checkright = keyindex+1
        ans.append(arr[keyindex])
        while len(ans)<k:
            if (checkright<=len(arr)-1) and (chekleft<0 or abs(arr[checkright]-x)<abs(arr[chekleft]-x)) :
                ans.append(arr[checkright])
                checkright+=1
            elif (chekleft>=0) and (checkright>len(arr)-1  or abs(arr[checkright]-x)>=abs(arr[chekleft]-x)):
                ans.insert(0,arr[chekleft])
                chekleft-=1         
        return ans 
        
