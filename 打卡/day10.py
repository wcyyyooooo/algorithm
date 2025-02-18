from collections import defaultdict
from functools import cache
class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        mp = defaultdict(int)
        ans = 0
        for r in rectangles:
            w, h = r[0], r[1]
            ans += mp[w / h]
            mp[w / h] += 1
        return ans
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        left = 0
        ans = 0
        for i, v in enumerate(values):
            ans = max(ans, v - i + left)
            left = max(left, i + v)
        return ans
class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(a : int) -> int:
            a = str(a)
            a = ''.join(reversed(a))
            return int(a)
        cnt = defaultdict(int)
        ans = 0
        for num in nums:
            ans += cnt[num - rev(num)]
            cnt[num - rev(num)] += 1
        return ans % int(1e9 + 7)
    
class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        min_idx, max_idx = 0, 0
        for j in range(indexDifference, len(nums)):
            i = j - indexDifference
            if nums[i] > nums[max_idx]: max_idx = i
            if nums[i] < nums[min_idx]: min_idx = i
            if nums[max_idx] - nums[j] >= valueDifference: return [max_idx, j]
            if nums[j] - nums[min_idx] >= valueDifference: return [min_idx, j]
        return [-1, -1]
    
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        left = prices[0]
        ans = 0
        for i in range(1, n):
            ans = max(prices[i] - left, ans)
            left = min(left, prices[i])
        return ans
    
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        ans = 0
        min_price = prices[0]
        for i in range(1, n):
            if prices[i] > min_price:
                ans += prices[i] - min_price
                min_price = prices[i]
            else:
                min_price = prices[i]
        return ans

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [[0, 0] for _ in range(2)]
        dp[0][0], dp[1][0] = -1e9, -1e9
        n = len(prices)
        for i in range(n):
            dp[0][0] = max(dp[0][0], -prices[i])
            dp[0][1] = max(dp[0][1], dp[0][0] + prices[i])
            dp[1][0] = max(dp[1][0], dp[0][1] - prices[i])
            dp[1][1] = max(dp[1][1], dp[1][0] + prices[i])
        return max(dp[0][1], dp[1][1])
    
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        dp = [[-1e9, 0] for _ in range(k)]
        n = len(prices)
        for i in range(n):
            dp[0][0] = max(dp[0][0], -prices[i])
            dp[0][1] = max(dp[0][1], dp[0][0] + prices[i])
            for j in range(1, k):
                dp[j][0] = max(dp[j][0], dp[j - 1][1] - prices[i])
                dp[j][1] = max(dp[j][1], dp[j][0] + prices[i])
        return max(dp[i][1] for i in range(k))
    
class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        n = len(energyDrinkA)
        dp = [[0, 0] for _ in range(n)]
        dp[0][0] = energyDrinkA[0]
        dp[0][1] = energyDrinkB[0]
        for i in range(1, n):
            dp[i][0] = dp[i - 1][0] + energyDrinkA[i]
            dp[i][1] = dp[i - 1][1] + energyDrinkB[i]
            if i >= 2:
                dp[i][0] = max(dp[i][0], dp[i - 2][1] + energyDrinkA[i])
                dp[i][1] = max(dp[i][1], dp[i - 2][0] + energyDrinkB[i])
        return max(dp[n - 1])
dp = [[[[0, 0, 0] for k in range(50 + 1)]for j in range(50 + 1)]for i in range(50 + 1)]
for i in range(50 + 1):
    for j in range(50 + 1):
        for k in range(50 + 1):
            # AB AA / BB AA\
            if i > 0:
                dp[i][j][k][0] = max(dp[i - 1][j][k][2], dp[i - 1][j][k][1]) + 2
            # AA BB 
            if j > 0:
                dp[i][j][k][1] = dp[i][j - 1][k][0] + 2
                # BB AB AB AB
                if k > 0:
                    dp[i][j][k][2] = max(dp[i][j][k - 1][1], dp[i][j][k - 1][2]) + 2
class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        return max(dp[x][y][z])
class Solution:
    def numberOfWays(self, s: str) -> int:
        cnt = defaultdict(int)
        ans = 0
        for i, c in enumerate(s):
            if c == '0':
                cnt['0'] += 1
                cnt['10'] += cnt['1']
                ans += cnt['01']
            if c == '1':
                cnt['1'] += 1
                cnt['01'] += cnt['0']
                ans += cnt['10']
        return ans
class Solution:
    def maxScore(self, a: List[int], b: List[int]) -> int:
        n = len(b)
        dp = [[-1e18, -1e18, -1e18, -1e18] for _ in range(n + 1)]
        for i in range(1, n + 1):
            dp[i][0] = max(dp[i - 1][0], b[i - 1] * a[0])
            if i >= 2:
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + b[i - 1] * a[1])
            if i >= 3:
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + b[i - 1] * a[2])
            if i >= 4:
                dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + b[i - 1] * a[3])
        return dp[n][3]
    
class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        maxlen, minlen = 0, 0
        ans = 0
        for num in nums:
            if num < 0:
                temp = minlen + 1 if minlen > 0 else 0
                minlen = maxlen + 1
                maxlen = temp 
            elif num == 0:
                maxlen, minlen = 0, 0
            else:
                maxlen += 1
                minlen = minlen + 1 if minlen > 0 else 0
            ans = max(ans, maxlen)
        return ans
    
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        cnt = [0, -1e9, -1e9] * 3
        for _, v in enumerate(nums):
            rec = cnt[0 : 3]
            for i in range(3):
                if rec[i] >= 0:
                    cnt[(i + v) % 3] = max(rec[(i + v) % 3], rec[i] + v)
        return cnt[0]
    
# x = digit[i] * 10 ^ i
class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        digits.sort(reverse = True)
        n = len(digits)
        dp = [[-1e9] * 3 for _ in range(n + 1)] 
        dp[0][0] = 0
        for i, v in enumerate(digits):
            for j in range(3):
                if dp[i][j] >= 0:
                    dp[i + 1][(j + v) % 3] = max(dp[i + 1][(j + v) % 3], dp[i][j] + v)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j])
        path = []
        v = int(dp[n][0])
        for i in range(n - 1, -1, -1):
            if dp[i][(v - digits[i]) % 3] == v - digits[i]:
                path.append(str(digits[i]))
                v -= digits[i]
        path.sort(reverse = True)
        if len(path) > 0 and path[0] == "0": return "0"
        return "".join(path)
    
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0, 0] for i in range(n + 1)]
        for i, v in enumerate(nums):
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + v)
            dp[i + 1][1] = max(dp[i][1], dp[i][0] - v)
        return max(dp[n])
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[-1e9, -1e9] for _ in range(n + 1)]
        dp[0][0] = 0
        ans = 0
        for i in range(n):
            dp[i + 1][0] = max(dp[i][0] + arr[i], 0)
            dp[i + 1][1] = max(dp[i][0], dp[i][1] + arr[i], 0)
            ans = max(dp[i + 1])
        return ans
# dp[i][0][0] -> dp[i][1][0]
# dp[i][0][0] -> dp[i][0][1]
class Solution:
    def maximumTotalCost(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[[0, 0] for j in range(2)] for i in range(n + 1)]
        for i in range(n):
            dp[i + 1][0][0] = max(dp[i][1][0] + nums[i], dp[i][0][1] + nums[i])
            dp[i + 1][1][0] = dp[i][0][0] - nums[i]
            dp[i + 1][0][1] = max(dp[i][1][1] + nums[i], dp[i][0][0] + nums[i])
            dp[i + 1][1][1] = dp[i][1][1] - nums[i]
        return max(dp[n])
    
    
class Solution:
    def knightDialer(self, n: int) -> int:
        nxt = [[4, 6], [6, 8], [7, 9], [4, 8], [0, 3, 9], [], [0, 1, 7], [2, 6], [1, 3], [2, 4]]
        dp = [1] * 10
        MOD = int(1e9 + 7)
        for _ in range(n - 1):
            rec = dp[0 : 10]
            dp = [0] * 10
            for j in range(10):
                for k in nxt[j]:
                    dp[j] = (dp[j] + rec[k]) % MOD
        return sum(dp) % MOD
    
class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        i, j = 0, 0
        s1, s2 = 0, 0
        while i < n and j < m:
            if nums1[i] < nums2[j]:
                s1 += nums1[i]
                i += 1
            elif nums1[i] > nums2[j]:
                s2 += nums2[i]
                j += 1
            else:
                s1, s2 = max(s1, s2) + nums1[i], max(s1, s2) + nums2[j]
                i += 1
                j += 1
        s1 += sum(nums1[i:])
        s2 += sum(nums2[j:])
        return max(s1, s2) % int(1e9 + 7)
    
class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        dp = [[0, 0] for _ in range(n)]
        dp[0][0], dp[0][1] = 0, 1
        for i in range(1, n):
            a1, a2 = nums1[i - 1], nums1[i]
            b1, b2 = nums2[i - 1], nums2[i]
            if (a1 < a2 and b1 < b2) and (a1 < b2 and b1 < a2):
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1])
                dp[i][1] = dp[i][0] + 1
            elif (a1 < a2 and b1 < b2):
                dp[i][0] = dp[i - 1][0]
                dp[i][1] = dp[i - 1][1] + 1
            else:
                dp[i][0] = dp[i - 1][1]
                dp[i][1] = dp[i - 1][0] + 1
        return min(dp[n - 1])
    
    
class Solution:
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        dp = [0] * 3
        MOD = int(1e9 + 7)
        for num in nums:
            if num == 0:
                # 不选0, dp[i][0] = dp[i - 1][0]
                # 选0 dp[i][0] += dp[i - 1][0] + 1
                dp[0] = (dp[0] * 2 + 1) % MOD
            elif num == 1:
                # 不选1 dp[i][1] = dp[i - 1][1]
                # 选1 dp[i][1] += dp[i - 1][1] + dp[i - 1][0]
                dp[1] = (dp[1] * 2 + dp[0]) % MOD
            else:
                dp[2] = (dp[2] * 2 + dp[1]) % MOD
        return dp[2]
                
class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        g = defaultdict(list)
        for edge in edges:
            g[edge[0]].append(edge[1])
            g[edge[1]].append(edge[0])
        # dp[root][0], dp[root][1] 以root为根，对root操作偶数次,除掉root的最大值
        # r0 = max(dp[nxt][0] + nums[nxt], dp[nxt][1] + nums[nxt] ^ k) 不对nxt和root进行操作
        # r1 = max(dp[nxt][1] + nums[nxt], dp[nxt][0] + nums[nxt] ^ k) 对nxt和root进行操作
        # dp0 = max(dp0 + r0, dp1 + r1) dp0 + r0为不操作的最大值
        # dp1 = max(dp0 + r1, dp0 + r0)
        @cache
        def dfs(root: int, fa: int) -> int:
            dp0, dp1 = 0, -inf
            for gi in g[root]:
                for nxt in gi:
                    r0, r1 = dfs(nxt, root)
                    dp0, dp1 = max(dp0 + r0, dp1 + r1), max(dp1 + r0, dp0 + r1)
            return max(dp0 + nums[root], dp1 + nums[root] ^ k), max(dp1 + nums[root], dp0 + nums[root] ^ k)
        return dfs(0, -1)[0]
                    