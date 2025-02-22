from collections import defaultdict
class Solution:
    def similarPairs(self, words: List[str]) -> int:
        cnt = defaultdict(int)
        ans = 0
        for word in words:
            s = ''.join(sorted(list(set(word))))
            ans += cnt[s]
            cnt[s] += 1
        return ans