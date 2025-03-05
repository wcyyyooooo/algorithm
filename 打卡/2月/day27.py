from collections import defaultdict
class Node:
    def __init__(self):
        self.son = [None] * 26
        self.isEnd = False
class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> int:
        cur = self.root
        for c in word:
            c = ord(c) - ord('a')
            if cur.son[c] == None:
                cur.son[c] = Node()
            cur = cur.son[c]
        cur.isEnd = True
    def find(self, word: str) -> int:
        cur = self.root
        for c in word:
            c = ord(c) - ord('a')
            if cur.son[c] == None:
                return 0
            cur = cur.son[c]
        return 2 if cur.isEnd else 1
    def search(self, word: str) -> bool:
        return self.find(word) == 2

    def startsWith(self, prefix: str) -> bool:
        return self.find(prefix) != 0

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        tr = Trie()
        tr.insert(strs[0])
        mx = len(strs[0])
        for s in strs[1:]:
            sz = 0
            cur = tr.root
            for c in s:
                c = ord(c) - ord('a')
                sz += 1
                if cur.son[c] == None:
                    cur.son[c] = Node()
                    break
            mx = min(mx, sz)
            tr.insert(s)
        return mx
class Node:
    def __init__(self):
        self.son = [None] * 26
        self.val = 0 
class MapSum:

    def __init__(self):
        self.root = Node()
        self.cnt = defaultdict(int)
    def insert(self, key: str, val: int) -> None:
        delta = val
        if self.cnt.get(key) != None:
            delta -= self.cnt[key]
        cur = self.root
        for c in key:
            c = ord(c) - ord('a')
            if cur.son[c] == None:
                cur.son[c] = Node()
            cur = cur.son[c]
            cur.val += delta

    def sum(self, prefix: str) -> int:
        cur = self.root
        for c in prefix:
            c = ord(c) - ord('a')
            if cur.son[c] == None:
                return 0
            cur = cur.son[c]
        return cur.val
class Node:
    def __init__(self):
        self.son = [None] * 26
        self.isEnd = False
class Trie:
    def __init__(self):
        self.root = Node()
    def insert(self, s : str) -> None:
        cur = self.root
        for c in s:
            c = ord(c) - ord('a')
            if cur.son[c] == None:
                cur.son[c] = Node()
            cur = cur.son[c]
        cur.isEnd = True
    def query(self, s : str) -> bool:
        cur = self.root
        for c in s:
            c = ord(c) - ord('a')
            if cur.son[c] == None:
                cur.son[c] = Node()
            cur = cur.son[c]
            if not cur.isEnd:
                return False
        return True
class Solution:
    def longestWord(self, words: List[str]) -> str:
        tr = Trie()
        ans = ""
        for word in words: tr.insert(word)
        for word in words:
            n, m = len(word), len(ans)
            if n < m: continue
            if n == m and word > ans: continue
            if tr.query(word):
                ans = word
        return ans
    
class Node:
    def __init__(self):
        self.son = [None] * 26
        self.words = []
class Trie:
    def __init__(self):
        self.root = Node()
    def insert(self, s : str) -> None:
        cur = self.root
        for c in s:
            c = ord(c) - ord('a')
            if cur.son[c] == None:
                cur.son[c] = Node()
            cur = cur.son[c]
            if len(cur.words) < 3:
                cur.words.append(s)
            else:
                cur.words.append(s)
                cur.words = sorted(cur.words)[0:3]
class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        tr = Trie()
        for product in products:
            tr.insert(product)
        isExist = False
        ans = []
        cur = tr.root
        for c in searchWord:
            c = ord(c) - ord('a')
            if isExist or cur.son[c] == None:
                ans.append([])
                isExist = True
            else:
                cur = cur.son[c]
                ans.append(sorted(cur.words[0:3]))
        return ans
class Node:
    def __init__(self):
        self.son = [None] * 26
class Trie:
    def __init__(self):
        self.root = Node()
    def insert(self, s : str) -> int:
        cur = self.root
        isNew = False
        for c in s:
            c = ord(c) - ord('a')
            if cur.son[c] == None:
                cur.son[c] = Node()
                isNew = True
            cur = cur.son[c]
        return len(s) + 1 if isNew else 0
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(lambda x : -len(x))
        tr = Trie()
        ans = 0
        for word in words:
            ans += tr.insert(word)
        return ans
class Node:
    def __init__(self):
        self.son = {}
        self.isEnd = False
class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        ans = 0
        n = len(nums)
        tr = Node()
        for i in range(len(nums)):
            x = 0
            cur = tr
            for j in range(i, n):
                if cur.son.get(nums[j]) == None:
                    cur.son[nums[j]] = Node()
                cur = cur.son[nums[j]]
                if nums[j] % p == 0: x += 1
                if x > k:
                    break
                if not cur.isEnd:
                    ans += 1
                    cur.isEnd = True
        return ans
                    