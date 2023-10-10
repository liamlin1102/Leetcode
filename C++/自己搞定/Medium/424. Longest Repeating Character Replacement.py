class Solution:
    # 這題很經典，思惟上的突破，根本不用管他們的順序
    def characterReplacement(self, s: str, k: int) -> int:
        # 如果你的k比長度少1 或是根長度一樣 那不論該字串為何都可以被轉化成同樣的
        if (k >=len(s)-1):
            return len(s)
        start=0;maxlen=0;max_str=0;dic={}
        for end in range (len(s)):
            # 如果這個字串第一次出現，加進去
            if not s[end]  in dic :
                dic[s[end]]=0
            # 如果他出現過加1
            dic[s[end]]+=1
            # 計算目前出現最多次的字母有幾次，這邊是核心，我們只需要去看最新右邊的那個字母有沒有比原本最多的次數大，因為它是唯一的變數
            max_str = max(max_str,dic[s[end]])
            # 如果發現結束跟開始的長度是比出現最多次數的字母+可修改次數還多，證明現在裡面有沒被改到的字母，不符合題目，因此把原來第一個字母扣掉，並開頭加1
            if end-start+1>max_str+k:
                dic[s[start]]-=1
                start+=1
            # 根據sliding window的特性，它只會越來越長，因此只要內部字母的最大長度有變長那就把長度也加1吧
            else:
                maxlen+=1
            # 無論如何向右走喔
            end+=1
        return maxlen
            
    def characterReplacement(self, s: str, k: int) -> int:
        ## RC ##
		## APPROACH : SLIDING WINDOW ##
        # Logic #
        # 1. Increase the window if the substring is valid else,
        # 2. slide the window with the same length. No need to shrink the window
        
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##
        # 預設數字的dict
        freqDict = defaultdict(int)
        maxFreq = 0
        maxLength = 0
        start = end = 0
        while end < len(s):
            # 依樣出現一次就+一次
            freqDict[s[end]] += 1
            
            # maxFreq may be invalid at some points, but this doesn't matter
            # maxFreq will only store the maxFreq reached till now
            # 一樣去比較看誰比較大
            maxFreq = max(maxFreq, freqDict[s[end]])
            
            # maintain the substring length and slide the window if the substring is invalid
            if ((end-start+1) - maxFreq) > k:
                freqDict[s[start]] -= 1
                start += 1
            else:
                # 唯一不一樣 理論上該方法也可以看哪個大去進行替換
                maxLength = max(maxLength, end-start+1)
            end += 1
        return maxLength