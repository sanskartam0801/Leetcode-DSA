class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        start = 0
        maxlen = 0

        for i,ch in enumerate(s):
            if ch in seen:
                start = max(start,seen[ch]+1)
            seen[ch] = i
            maxlen = max(maxlen,i-start+1)
        return maxlen