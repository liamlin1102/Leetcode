class Solution:
    # 解題思緒，理論上會變動的只有最左跟最右，由於窗口會移動，有可能最大值傳遞的時候本體已經跌落窗口，因此要同時檢查最大值為多少以及是否該最大值還在window裡
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # 如果長度1回傳本體
        if len(nums)==1:
            return nums
        # 做一個雙向的queue 來進行同時儲存最大值以及檢查位置，該queue負責儲存index
        ans=[];start = 0 ;end = 0;queue=[]
        for index,num in enumerate(nums):
            # 當queue內部還有東西，並且nums[queue[-1]]比現在的值小(代表queue的queue轉換成num 的最小值比現在的值還小)
            while queue and nums[queue[-1]]<=num:
                # 由於我們是要找最大值，因此我們要一直把最後一個踢出去，只要踢出去迴圈就會重新檢查一次，如果是小就在踢這樣就可以找出所有比這個小
                queue.pop()
            # 把現在的index往後加進去，這樣就符合前面一個數值一定比他大，或是上面清空後他是第一個值(最大)
            queue.append(index)
            # 如果長度不到window，跳過
            if index-start+1!=k:
                continue 
            # 把最大值加進去 
            ans.append(nums[queue[0]])
            # 如果發現最大值的index跟start同樣，代表他馬上就要消失了，所以把它扣掉
            if start==queue[0]:
                queue.pop(0)
            start+=1
        return ans


    # def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
    #     if len(nums)==1:
    #         return nums
    #     ans=[];start = 0 ;end = 0;queue=[]
    #     for index,num in enumerate(nums):
    #         while queue and queue[-1]<=num:
    #             queue.pop()
    #         queue.append(index)
    #         if index-start+1!=k:
    #             continue 
    #         ans.append(nums[queue[0]])
    #         if nums[start]==queue[0]:
    #             queue.pop(0)
    #         start+=1
    #     return ans
             
