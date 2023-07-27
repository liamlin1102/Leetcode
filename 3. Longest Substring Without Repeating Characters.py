class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 創一個hashmap來儲存文字的位置跟值
        start = 0;end=0;maxlen = 0;dic={}
        # 當目前沒到底
        while(end<len(s)):
            # 如果字在字典裡(代表重複)。並且去查詢這個文字的位置要有比起點高(比起點低代表不用被探討，因為等於你倒著算)
            if s[end]in dic and dic[s[end]]>=start :
                # 更新最大長度
                maxlen = max(maxlen,end-start)
                # 並且將起點設定為重複的值下一個點
                start = dic[s[end]]+1
            # 任何字都加進字典裡，以確認後續是否出現
            dic[s[end]]=end
            # 一直往右走
            end+=1
        # 避免最後一個數字沒出現重複，最後要計算一次
        maxlen = max(maxlen,end-start)
        return maxlen

    # 解法2
    def lengthOfLongestSubstring(self, s):
        start = maxLength = 0
        usedChar = {}  
        for i in range(len(s)):
        
            if s[i] in usedChar and start <= usedChar[s[i]]:
                start = usedChar[s[i]] + 1
                # 跟上面不同，這裡根本不用去想長度有沒有變長，因為如果進來這裡就代表重複了，代表長度上次就是這次的最長了，因此你不用計算
            else:
                # 只要沒有重複都計算記得
                maxLength = max(maxLength, i - start + 1)

            usedChar[s[i]] = i

        return maxLength