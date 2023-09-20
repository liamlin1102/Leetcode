# 解題思路，有幾種內涵a b c 的 subarray，我們只要去找最右邊新增並符合題目要求那一刻，此時右邊所有的sub array都會符合
# 因此找右邊的點找到後，把總長度-最右邊指針然後加進去總次數，並移動左指針以看看右指針是否變動
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        left=0;right=0;dic={"a":0,"b":0,"c":0};ans=0;length=len(s)#由於題目說只有a,b,c組成，這樣去檢查
        while right<length:#當sliding右邊碰到
            dic[s[right]]+=1
            # 當dictionary裡面符合都有abc
            while dic["a"]!=0 and dic["b"]!=0 and dic["c"]!=0:
                # 把剩下的長度都加進去
                ans +=(length-right)
                # 把左邊的扣掉
                dic[s[left]]-=1
                # 左邊往前走
                left+=1
            # 無條件右邊往前走
            right+=1
        return ans