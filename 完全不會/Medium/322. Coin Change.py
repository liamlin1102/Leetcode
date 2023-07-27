# Bottom Up
# 解題思路
# 1. 確認狀態
# 2. 確定base case
# 3. 定義狀態方程式
# 這題不論往下還是往上都要思考一個問題，我們該儲存的資訊是剩餘多少錢還是以花了幾個硬幣。
# 會發現我們要存花了幾個硬幣，原因是如果用剩餘多少錢會沒辦法直觀知道花了幾個硬幣(不符合題目)
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:        
        # 首先創造預算數量+1的無限大值list，晚點解釋為什麼是無限大
        dp=[math.inf] * (amount+1)
        # 要知道預算0 當然用0個硬幣
        dp[0]=0
        # 這邊可以倒過來，但這樣寫最好，為什麼? 因為我們根本不用去從頭到尾數硬幣，我們只要從每一個硬幣的值開始算
        for coin in coins:
            # 透過用每一個硬幣去定義狀態方程式，這樣可以最小化狀態列，因為我們是從該硬幣開始跑，因此會從最小的basecase開始
            # 這邊就是關鍵了 為什麼要用無限大，因為是有可能硬幣湊不齊的，因此我們要如何定義狀態方程式，我們要找dp[i]跟dp[i-目前硬幣]的最小值
            # 比方說 我舉個例子 假設預算8 有 2 3 5 三種硬幣，
            # 那假設我們先跑2 因為是假設inf的list 那dp[2]=1 dp[4]=2 dp[6]=3 dp[8] = 4 
            # 如果是dp[2]我們會去抓 dp[2] or dp[2-2]+1 的最小值 那很明顯就會抓後者 dp[2]=dp[0]+1
            # 如果是dp[3]我們會去抓 dp[3] or dp[3-2]+1 的最小值 那很明顯倆著都是inf不抓
            # 那如果是0的list呢?
            # 如果是dp[2]我們會去抓 dp[2] or dp[2-2]+1 的最小值 那很明顯就會抓前者 dp[2]=dp[2]=0
            # 如果是dp[3]我們會去抓 dp[3] or dp[3-2]+1 的最小值 那很明顯倆著都是 0  有發現嗎 都會抓到0 要有大小才能繼續
            for i in range(coin, amount+1):
                dp[i]=min(dp[i], dp[i-coin]+1)
            # coin並不需要調整怎麼說呢，因為會把各種可能給重構，先跑3 會建構到6 那這樣用2 跑到8 8-2 = 6 
        return -1 if dp[-1]==math.inf else dp[-1]
# Top Down
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:            
        def coinChangeInner(rem, cache):
            # 如果小於0 代表沒有剛好湊到 回傳無限大
            if rem < 0:
                return math.inf
            # 如果等於代表剛好湊到 傳0回來(因為本來就會+1了)
            if rem == 0:                    
                return 0
            # 如果有值就別算了 直接提出來    
            if rem in cache:
                return cache[rem]
            # 一樣最小值
            cache[rem] = min(coinChangeInner(rem-x, cache) + 1 for x in coins)                         
            return cache[rem]      
        
        ans = coinChangeInner(amount, {})
        return -1 if ans == math.inf else ans     
    # DP寫法
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 如果預算為0沒有任何方法
        if amount==0:return 0
        # 先創造一個amount+1的list 存放無窮大的數，這裡為方法總數
        dp=[math.inf]*(amount+1);dp[0]=0#給定第一個值為0，這樣把預算-coin就可以知道是否為0(代表可以用該硬幣支付)
        for coin in coins:#這題一定要先跑所有的硬幣再跑預算，以免沒有更新到方法最小值
            for index in range(coin,amount+1):#從該幣值開始到預算，逐步更新計算方法
                if dp[index-coin]!=math.inf:#inf不能運算                  
                    dp[index] = min(dp[index],dp[index-coin]+1)
        
        return dp[amount] if dp[amount] !=math.inf else -1
