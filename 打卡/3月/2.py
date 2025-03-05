class Node:
    def __init__(self):
        self.son = [None] * 26
        self.min_l = inf
        self.i = 0
class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        ord_a = ord('a')
        root = Node()
        for idx, s in enumerate(wordsContainer):
            l = len(s)
            cur = root
            if l < cur.min_l:
                cur.min_l = l
                cur.i = idx
            for c in map(ord, reversed(s)):
                c -= ord_a
                if cur.son[c] == None:
                    cur.son[c] = Node()
                cur = cur.son[c]
                if l < cur.min_l:
                    cur.min_l = l
                    cur.i = idx
        ans = []
        for s in wordsQuery:
            cur = root
            for c in map(ord, reversed(s)):
                c -= ord_a
                if cur.son[c] == None:
                    break
                cur = cur.son[c]
            ans.append(cur.i)
        return ans