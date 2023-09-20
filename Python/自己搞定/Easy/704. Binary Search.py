#  (lower mid，無條件捨去)或是(upper mid，無條件進位)
class Solution:
    # 最佳解
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)-1
        # 用BS的方法
        # 還有這裡的方式，原則上這題為了最快的速度，我們是要找符合的數字，而非收斂一個最佳解，因此我們使用把r>=l，並且當mid重新定義時高的-1 低的+1 ，此時就會travel所有的數字
        # 但注意由於遍歷完後，right會小於left，代表不會收斂在同一個點上，因此要在迴圈找出解答，沒找出就是答案不存在
        while left<=right:
            # 這邊重點解釋，正常來說你會覺得中間值，(高-低)/2，但為什麼這裡是(高+低)/2?
            # 因為我們會重新定義高跟低的值，舉個例子，今天有10個數字，低=0，高=9，中間會是4.5(選用 (lower mid))，mid=4，
            # 此時如果要找的數字是第3個，4>3，代表要往下找，高會被定義成mid 因此變成，低=0,高=4,此時mid會變成4+0/2=2
            # 此時2<3，代表往上找，低會被定義成mid，因此變成，低=2、高=4
            # 此時會發生什麼事情，如果用高-低會變成(4-2)/2 = 1，這樣一輩子都找不到，但如果用加的呢?(4+2)/2=3，就找到答案了
            # 因此BS算中間值一律都用高+低/2，前提是會重新賦值高、低
            mid = (left+right)//2
            # 如果命中，回傳值
            if nums[mid]==target:
                return mid
            # 如果比較大，重新定義高點(往右找)
            elif nums[mid]>target:
                right = mid-1
            # 如果比較小，重新定義低點(往低找)
            else:
                left = mid+1   
        return -1
    
    def search(self, nums: List[int], target: int) -> int:
        # 如果比最大值大或比最小值小就直接回傳-1
        if target>nums[-1] or target<nums[0]:
            return -1    
        ans = 0
        # 
        while len(nums)>0:
            mid_ind = int(len(nums)/2)
            if target!=nums[mid_ind] and len(nums)==1:
                return -1
            if target==nums[mid_ind]:
                return ans+mid_ind
            elif target >nums[mid_ind]:
                nums = nums[mid_ind:]
                ans +=mid_ind
            else:
                nums = nums[:mid_ind]
        return ans 



# recrusion版本有夠爛
    # def search(self, nums: List[int], target: int) -> int:        
    #     if target>nums[-1] or target<nums[0]:
    #         return -1 
    #     mid_ind = int(len(nums)/2)
    #     if len(nums)==1 and nums[0]!=target:
    #         return -1
    #     if target==nums[mid_ind]:
    #         return mid_ind
    #     elif target>nums[mid_ind]:
    #         ans =self.search(nums[mid_ind+1:],target)
    #         if ans == -1:
    #             return -1
    #         return(mid_ind+ans+1)
    #     else:
    #         ans =self.search(nums[:mid_ind],target)
    #         if ans == -1:
    #             return -1
    #         return(ans)