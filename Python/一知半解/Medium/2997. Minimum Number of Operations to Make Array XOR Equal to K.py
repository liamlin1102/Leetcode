class Solution:
    def minOperations(self, nums, k):
        answer = 0
        for num in nums:
            answer ^= num
        if answer == k:
            return 0
        answerK = answer ^ k
        binAnswer = bin(answerK).count('1')
        return binAnswer
