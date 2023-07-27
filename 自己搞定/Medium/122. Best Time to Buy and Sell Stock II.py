class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 持有股票的報酬 負無限大 因為根本不可能存在只持有不賣出
        # 賣出股票的報酬 0 因為 目前手上的股票價值為0 賣出也為0
        # It is impossible to sell stock on first day, set -infinity as initial value for cur_hold
        cur_hold, cur_not_hold = -float('inf'), 0
        
        for stock_price in prices:
            
            prev_hold, prev_not_hold = cur_hold, cur_not_hold
            #檢查現在的最大值，並用利潤計算，如果買進來比持有的價格更大，代表要買進，基本上就是更新了cur_not_hold就會買進啦
            #由於此題目不限制買賣次數，因此只要手頭上沒有股票就該買進，反正遇到下一個更便宜的會因為max( prev_hold, prev_not_hold - stock_price )去自動換成更便宜的
			# either keep hold, or buy in stock today at stock price
            cur_hold = max( prev_hold, prev_not_hold - stock_price )
			#檢查現在的最大值，並用身上的盈餘計算，如果賣掉的最大值比身上的盈餘多，代表要賣出，基本上就是一旦遇到比當初購買的大就會賣出啦
            #由於此題目不限制買賣次數，因此只要價格比購買價低就會直接賣掉，反正遇到下一個更便宜他也會在買進來並且在下一個高點賣出
			# either keep not-hold, or sell out stock today at stock price
            cur_not_hold = max( prev_not_hold, prev_hold + stock_price )
            
        # maximum profit must be in not-hold state
        return cur_not_hold

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        @cache
        def trade(day_d):
            
            if day_d == 0:
                
                # Hold on day_#0 = buy stock at the price of day_#0
                # Not-hold on day_#0 = doing nothing on day_#0
                return -prices[day_d], 0
            
            prev_hold, prev_not_hold = trade(day_d-1)
            
            hold = max(prev_hold, prev_not_hold - prices[day_d] )
            not_hold = max(prev_not_hold, prev_hold + prices[day_d] )
            
            return hold, not_hold
        
        # --------------------------------------------------
        last_day= len(prices)-1
        
        # Max profit must come from not_hold state (i.e., no stock position) on last day
        return trade(last_day)[1]