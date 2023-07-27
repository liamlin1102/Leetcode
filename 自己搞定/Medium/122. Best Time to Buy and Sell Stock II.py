class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # �����Ѳ������S �t�L���j �]���ڥ����i��s�b�u��������X
        # ��X�Ѳ������S 0 �]�� �ثe��W���Ѳ����Ȭ�0 ��X�]��0
        # It is impossible to sell stock on first day, set -infinity as initial value for cur_hold
        cur_hold, cur_not_hold = -float('inf'), 0
        
        for stock_price in prices:
            
            prev_hold, prev_not_hold = cur_hold, cur_not_hold
            #�ˬd�{�b���̤j�ȡA�åΧQ��p��A�p�G�R�i�Ӥ�����������j�A�N��n�R�i�A�򥻤W�N�O��s�Fcur_not_hold�N�|�R�i��
            #�ѩ��D�ؤ�����R�榸�ơA�]���u�n���Y�W�S���Ѳ��N�ӶR�i�A�ϥ��J��U�@�ӧ�K�y���|�]��max( prev_hold, prev_not_hold - stock_price )�h�۰ʴ�����K�y��
			# either keep hold, or buy in stock today at stock price
            cur_hold = max( prev_hold, prev_not_hold - stock_price )
			#�ˬd�{�b���̤j�ȡA�åΨ��W���վl�p��A�p�G�汼���̤j�Ȥ񨭤W���վl�h�A�N��n��X�A�򥻤W�N�O�@���J������ʶR���j�N�|��X��
            #�ѩ��D�ؤ�����R�榸�ơA�]���u�n������ʶR���C�N�|�����汼�A�ϥ��J��U�@�ӧ�K�y�L�]�|�b�R�i�ӨåB�b�U�@�Ӱ��I��X
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