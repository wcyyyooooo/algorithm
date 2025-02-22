from collections import defaultdict, Counter
import bisect
from itertools import accumulate
class NumArray:
    def __init__(self, nums: List[int]):
        n = len(nums)
        pre = [0] * (n + 1)
        for i, v in enumerate(nums):
            pre[i + 1] = pre[i] + v
        self.pre = pre
    def sumRange(self, left: int, right: int) -> int:
        return self.pre[right + 1] - self.pre[left]
    
class Solution:
    def subarraySum(self, nums: List[int]) -> int:
        n = len(nums)
        pre = [0] * (n + 1)
        for i, v in enumerate(nums):
            pre[i + 1] = pre[i] + v
        ans = 0
        for i in range(n):
            start = max(0, i - nums[i])
            ans += pre[i + 1] - pre[start]
        return ans

class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        pre = [0] * (n + 1)
        for i, v in enumerate(nums):
            pre[i + 1] = pre[i] + v
        ans = [0] * len(queries)
        for i in range(len(queries)):
            ans[i] = bisect.bisect_right(pre[1:], queries[i])
        return ans

class Solution:
    def shiftDistance(self, s: str, t: str, nextCost: List[int], previousCost: List[int]) -> int:
        pre_sum = [0] * 53
        nxt_sum = [0] * 53
        for i in range(52):
            pre_sum[i + 1] = pre_sum[i] + nextCost[i % 26]
            nxt_sum[i + 1] = nxt_sum[i] + previousCost[i % 26]
        ans = 0
        for i in range(len(s)):
            x = ord(s[i]) - ord('a')
            y = ord(t[i]) - ord('a')
            ans += min(nxt_sum[y if y > x else y + 26] - nxt_sum[x], pre_sum[x + 1 if y < x else x + 27] - pre_sum[y + 1])
        return ans

class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        plate = [0] * (n + 1)
        r = [-1] * (n + 1)
        l = [-1] * (n + 1)
        for i in range(1, n):
            l[i] = i if s[i] == '|' else l[i - 1]
        for i in range(n - 2, -1, -1):
            r[i] = i if s[i] == '|' else r[i + 1]
        for i in range(n):
            plate[i + 1] = plate[i] + (s[i] == '*')
        ans = []
        for query in queries:
            a, b = query[0], query[1]
            c, d = r[a], r[b]
            if c != -1 and c <= d:
                ans.append(plate[d + 1] - plate[c])
        return ans
    
class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(candiesCount)
        pre_sum = [0] * (n + 1)
        for i, v in enumerate(candiesCount):
            pre_sum[i + 1] = pre_sum[i] + v
        res = []
        for query in queries:
            t, day, cap = query[0], query[1], query[2]
            pre = pre_sum[t]
            ans = True
            if pre + 1 > (day + 1) * cap:
                ans = False
            if pre + candiesCount[t] < day + 1:
                ans = False
            res.append(ans)
        return res
    
class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        cnt = [1, 0]
        pre = 0
        ans = 0
        MOD = int(1e9 + 7)
        for v in arr:
            pre += v
            ans = (ans + cnt[pre % 2 ^ 1]) % MOD
            cnt[pre % 2] += 1
        return ans
    
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        cnt = defaultdict(int)
        pre = 0
        cnt[0] = 1
        ans = 0
        for num in nums:
            pre += num
            ans += cnt[(k + pre % k) % k]
            cnt[(pre + k) % k] += 1
            pre = pre % k
        return ans
    
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        pre = 0
        cnt = defaultdict(int)
        cnt[0] = 1
        ans = 0
        for num in nums:
            pre += num
            ans += cnt[(k + pre % k) % k]
            cnt[pre % k] += 1
            ans -= 1 if num % k == 0 else 0
            pre %= k
        return ans > 0
    
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        cnt = defaultdict(int)
        pre = 0
        ans = 0
        cnt[0] = -1
        for i, v in enumerate(nums):
            v = 1 if v == 1 else -1
            pre += v
            if cnt.get(pre) != None:
                ans = max(i - cnt[pre], ans)
            if cnt.get(pre) == None:
                cnt[pre] = i
            else: cnt[pre] = min(cnt[pre], i)
        return ans
    
class Solution:
    def findLongestSubarray(self, array: List[str]) -> List[str]:
        cnt = defaultdict(int)
        pre = 0
        ans = 0
        cnt[0] = -1
        max_r, max_l = 0, 0
        for i, v in enumerate(array):
            x = 1 if '0' <= v[0] <= '9'  else -len(v)
            pre += x
            if cnt.get(pre) != None:
                if i - cnt[pre] > ans:
                    max_l = cnt[pre]
                    max_r = i
                    ans = i - cnt[pre]
                elif i - cnt[pre] == ans and cnt[pre] < max_l:
                    max_r = i
                    max_l = cnt[pre]
            if cnt.get(pre) == None:
                cnt[pre] = i
            else: cnt[pre] = min(cnt[pre], i)
        return array[max_l + 1 : max_r  + 1]     
    
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        pre = [0] * (n + 1)
        for i, v in enumerate(nums):
            pre[i + 1] = pre[i] + v
        cnt = defaultdict(int)
        ans = -int(1e18)
        if k == 0: ans = max(nums)
        for i, v in enumerate(nums):
            if cnt.get(v + k) != None:
                ans = max(ans, pre[i + 1] - pre[cnt[v + k]])
            if cnt.get(v - k) != None:
                ans = max(ans, pre[i + 1] - pre[cnt[v - k]])
            if cnt.get(v) != None:
                if pre[cnt[v]] > pre[i]: cnt[v] = i 
            else: cnt[v] = i
        return ans if ans != -int(1e18) else 0
    
class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        cnt = defaultdict(int)
        n = len(nums)
        pre = [0] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] + nums[i] 
        ans = -int(1e18)
        cnt[0] = 0
        for i, v in enumerate(nums):
            idx = i + 1
            if cnt.get(idx % k) != None and idx - cnt[idx % k] >= k:
                ans = max(ans, pre[idx] - pre[cnt[idx % k]]) 
            if cnt.get(idx % k) != None:
                if pre[cnt[idx % k]] > pre[idx]:
                    cnt[idx % k] = idx
            else: cnt[idx % k] = idx
        return ans

class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        cnt = defaultdict(int)
        n = len(arr)
        # pre[i] - pre[j] = target
        left = [1e9] * (n + 1)
        cnt[0] = 0
        pre = 0
        for i in range(1, n + 1):
            left[i] = left[i - 1]
            pre += arr[i - 1]
            if cnt.get(pre - target) != None:
                left[i] = min(i - cnt[pre - target], left[i])
            cnt[pre] = i
        cnt.clear()
        cnt[0] = n + 1
        right = [1e9] * (n + 2)
        suf = 0
        for i in range(n, -1, -1):
            right[i] = right[i + 1]
            suf += arr[i - 1]
            if cnt.get(suf - target) != None:
                right[i] = min(cnt[suf - target] - i, right[i])
            cnt[suf] = i
        ans = 1e9
        print(left)
        print(right)
        for i in range(1, n + 1):
            ans = min(ans, left[i] + right[i + 1], left[i - 1] + right[i])
        return -1 if ans == 1e9 else ans
    
class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        pre = 0
        cnt = defaultdict(int)
        cnt[0] = 0
        ans = 0
        for num in nums:
            pre += num
            if cnt.get(pre - target) != None:
                ans += 1
                cnt.clear()
                cnt[0], pre = 0, 0
            else: cnt[pre] = 1
        return ans
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        cnt = Counter({0:1})
        ans = 0
        n = len(nums)
        x, idx = 0, nums.index(k)
        # 左侧大于k的加1 小于k的减一
        for i in range(idx - 1, -1, -1):
            x += 1 if nums[i] > k else -1
            cnt[x] += 1
        x = 0
        # 左侧小于 + 右侧小于 = 左侧大于 + 右侧大于
        # 左侧大于 - 左侧小于 = 右侧小于 - 右侧大于
        ans = cnt[0] + cnt[1]
        for i in range(idx + 1, n):
            x += 1 if nums[i] < k else -1
            ans += cnt[x] + cnt[x + 1]
        return ans

class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        # (sum - (pre[i] - pre[j])) % p = 0
        # (sum % p = (pre[i] - pre[j]) % p)
        pre = 0
        cnt = defaultdict(int)
        s, n = sum(nums), len(nums)
        if s % p == 0 : return 0
        cnt[s % p] = -1
        ans = n
        for i, v in enumerate(nums):
            pre += v
            cnt[(s + pre) % p] = i
            if cnt.get(pre % p) != None:
                ans = min(ans, i - cnt[pre % p])
        return -1 if ans == n else ans
    
class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        right_s = sum(nums)
        left_s = 0
        ans = [0] * len(nums)
        for i, v in enumerate(nums):
            ans[i] = i * v - left_s + right_s - (len(nums) - i) * v
            left_s += v
            right_s -= v
        return ans
class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        # |i - j| 
        # 只要把索引加入数组就可以做到单调的与上题一样
        cnt = defaultdict(list)
        ans = [0] * len(nums)
        for i, v in enumerate(nums):
            cnt[v].append(i)
        for _, v in cnt.items():
            n = len(v)
            right_s = sum(v)
            left_s = 0
            for i in range(n):
                ans[v[i]] = i * v[i] - left_s + right_s - (n - i) * v[i]
                left_s += v[i]
                right_s -= v[i]
        return ans
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        pre = [0] * (n + 1)
        for i in range(1, n + 1):
            pre[i] = pre[i - 1] ^ arr[i - 1]
        ans = []
        for query in queries:
            ans.append(pre[query[1] + 1] ^ pre[query[0]])
        return ans
class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        n, s = len(nums), sum(nums)
        ans = []
        pre = [0] * (n + 1)
        nums.sort()
        for i in range(1, n + 1):
            pre[i] = pre[i - 1] + nums[i - 1]
        for query in queries:
            i = bisect.bisect_left(nums, query)
            left_s = pre[i]
            right_s = s - left_s
            ai = (i) * query + right_s - left_s - (n - i) * query
            ans.append(ai)
        return ans
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        n = len(s)
        pre = [0] * (n + 1)
        for i in range(1, n + 1):
            pre[i] = pre[i - 1] ^ (1 << (ord(s[i]) - ord('a')))
        res = []
        for l, r in queries:
            bits = (pre[r + 1] ^ pre[l]).bit_count()
            res.append(bits)
        return res
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        l = list('aeiou')
        cnt = defaultdict(int)
        pre, ans, n = 0, 0, len(s)
        cnt[0] = -1
        for i in range(n):
            for j, k in enumerate(l):
                if s[i] == k:
                    pre ^= (1 << j)
            if cnt.get(pre) != None:
                ans = max(ans, i - cnt[pre])
            else: cnt[pre] = i
        return ans
class Solution:
    def longestAwesome(self, s: str) -> int:
        n = len(s)
        pre, ans = 0, 0
        cnt = defaultdict(int)
        cnt[0] = -1
        for i in range(n):
            pre = pre ^ (1 << (ord(s[i]) - ord('a')))
            if cnt.get(pre) != None: ans = max(ans, i - cnt[pre])
            else: cnt[pre] = i
            for k in range(10):
                if cnt.get(pre ^ (1 << k)) != None:
                    ans = max(ans, i - cnt[pre ^ (1 << k)])
        return ans
class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        n = len(word)
        cnt = defaultdict(int)
        cnt[0] = 1
        pre, ans = 0, 0
        for i in range(n):
            pre = pre ^ (1 << (ord(word[i]) - ord('a')))
            ans += cnt[pre]
            for j in range(26):
                ans += cnt[pre ^ (1 << j)]
            cnt[pre] += 1
        return ans