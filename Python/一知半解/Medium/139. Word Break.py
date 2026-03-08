class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False]*len(s)
        word_set = set(wordDict)
        allword = []
        for index,word in enumerate(s):
            allword.append(word)
            nowWord = "".join(allword)
            print(nowWord in word_set)
            if nowWord in word_set:
                dp[index] = True
            else:
                for start in range(index):
                    if dp[start] and s[start+1:index+1] in word_set:
                        dp[index] = True
                        break
        return dp[-1]