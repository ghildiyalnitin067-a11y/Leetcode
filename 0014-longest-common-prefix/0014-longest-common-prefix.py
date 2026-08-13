class Solution:
    def longestCommonPrefix(self, strs):
        ans = ""

       
        for i, ch in enumerate(strs[0]):

            
            for word in strs[1:]:
                if i >= len(word) or word[i] != ch:
                    return ans

            ans += ch

        return ans