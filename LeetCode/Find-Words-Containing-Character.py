class Solution(object):
    def findWordsContaining(self, words, x):
        """
        :type words: List[str]
        :type x: str
        :rtype: List[int]
        """

        ans = []
        for index,word in enumerate(words):
            if x in word:
                ans.append(index)

        return ans
        