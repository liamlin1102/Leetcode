class Solution:
    # sliding window
    def maxProfit(self, prices: List[int]) -> int:
        # 如果長度只有一個那賺個鎚子
        if len(prices)==1:
            return 0
        left=0;right=0;maxprofit=0;maxprice = 0
        # 當你的價格還沒到最右邊前一個
        while(right<=len(prices)-2):
            # 先往右邊加1
            right+=1
            # 比較左邊跟右邊一個，如果右邊大比較大才代表有利潤
            if prices[left]<prices[right]:  
                # 如果此時的右邊的值比目前遇到的所有最大的值還大，代表該利潤為新的最大利潤
                if prices[right]>maxprice: 
                    # 把最大的價格定義成現在的右邊
                    maxprice =  prices[right]  
                    # 去比較最大利潤，因為這只是這次最小值計算的最大利潤，並非一定最大            
                    maxprofit = max(maxprice-prices[left] ,  maxprofit)            
            else:
                # 如果發現右邊出現更小的值，就把開頭定在這個更小的值，並且去跑
                left=right
                # 重定義最大的價格，這一點很重要，因為即便新的最小值右邊價格出現的最大值比原來的小，但有可能因為本金變得更小導致利潤更大，因此重設最大值
                maxprice =  0
        return maxprofit
            



# 簡易解法
# 解題思緒:跑一圈找目前的值是否最小，並且去算每一個點的profit後去比較跟最大的profit比哪個大
    def maxProfit(self, prices: List[int]) -> int:
        minprice = prices[0];profit = 0
        # 從左到右跑一圈
        for i in range(len(prices)):
            # 去比較最小的值跟現在的價格哪個小
            minprice = min(prices[i],minprice)
            # 用當今的價夾去-這個最小的價格，以及去比較原來的Profit
            profit = max(profit,prices[i]-minprice)
        return profit