class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        dic = {}
        for index,num in enumerate(numbers):
            # 如果那個值在裡面，那就回傳
            if (target-num in dic):
                return[dic[target-num],index+1]
            # 如果沒有就加進map
            dic[num]=index+1