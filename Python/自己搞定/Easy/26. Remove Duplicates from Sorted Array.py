# <!-- https://leetcode.com/problems/remove-duplicates-from-sorted-array/solutions/2107606/py-all-4-methods-intuitions-walk-through-wrong-answer-explanations-for-beginners-python/?orderBy=hot&languageTags=python3 -->
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow =0;fast = 1
        # 如果發現有重複的就交換，並且把慢指針往前
        for i in range(len(nums)-1):
            if nums[slow]!=nums[fast]:
                slow+=1
                nums[slow]=nums[fast]
            fast+=1
        return slow+1