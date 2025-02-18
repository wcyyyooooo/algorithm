from collections import defaultdict, Counter
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        cnt = defaultdict(list)
        for i, v in enumerate(nums):
            if len(cnt[v]) != 0:
                for j in cnt[v]:
                    if i - j <= k:
                        return True
            cnt[v].append(i)
        return False
class Solution:
    def maxSum(self, nums: List[int]) -> int:
        cnt = [0] * 10
        ans = 0
        def cal(v : int) -> int:
            ans = v % 10
            while v > 0:
                v //= 10
                ans = max(ans, v % 10)
            return ans
        for num in nums:
            mx = cal(num)
            if cnt[mx] != 0:
               ans = max(num + cnt[mx], ans)
            cnt[mx] = max(cnt[mx], num)
        return ans if ans != 0 else -1
    
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        cnt = defaultdict(int)
        ans = 0
        for num in nums:
            if cnt[k - num] != 0:
                ans += 1
                cnt[k - num] -= 1
            else:
                cnt[num] += 1
        return ans
    
class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        mp = defaultdict(int)
        ans = len(cards) + 1
        for i, card in enumerate(cards):
            if mp.get(card) != None:
                ans = min(ans, i - mp[card] + 1)
            mp[card] = i 
        return -1 if ans == len(cards) + 1 else ans
    
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        mp = defaultdict(int)
        ans = 0
        for t in time:
            ans += mp [(60- t % 60) % 60]
            mp[t % 60] += 1
        return ans
class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        def gcd(a : int, b : int) -> int:
            if b != 0:
                return gcd(b, a % b)
            return a
        cnt = defaultdict(int)
        ans = 0
        for num in nums:
            x = int(str(num)[0])
            y = int(str(num)[-1])
            for i in range(1, 10):
                if gcd(i, y) == 1: ans += cnt[i]
            cnt[x] += 1
        return ans
    
class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        cnt = defaultdict(int)
        ans = 0
        for hour in hours:
            ans += cnt[(24 - hour % 24) % 24]
            cnt[hour % 24] += 1
        return ans
class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        pre = [0] * (len(nums) + 1)
        n = len(nums)
        for i, v in enumerate(nums):
            pre[i + 1] = pre[i] + v
        def cal(l1 : int, l2 : int) -> int:
            left = 0
            ans = 0
            for i in range(l1 + l2, n + 1):
                left = max(left, pre[i - l2] - pre[i - l1 - l2])
                ans = max(ans, left + pre[i] - pre[i - l2])
            return ans
        return max(cal(firstLen, secondLen), cal(secondLen, firstLen))
    
class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        cnt = defaultdict(int)
        for c in range(n - 2, 1, -1):
            cnt[nums[c + 1]] += 1
            for a in range(n):
                for b in range(a + 1, c):
                    ans += cnt[nums[a] + nums[b] + nums[c]]
        return ans
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        cnt = Counter(x + y for x in nums1 for y in nums2)
        return sum(cnt[-x - y] for x in nums3 for y in nums4)

class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:
        s = sum(nums)
        cnt = defaultdict(list)
        for i, v in enumerate(nums): cnt[v].append(i)
        ans = -1e9
        for i, v in enumerate(nums):
            d = s - v
            print(d % 2)
            if d % 2 == 0:
                for j in cnt[d // 2]:
                    if i != j:
                        ans = max(ans, v)
        return ans
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)
        s = " " + s
        left = [[0] * 26 for _ in range(n + 2)]
        right = [[0] * 26 for _ in range(n + 2)]
        for i in range(1, n + 1):
            for j in range(26):
                left[i][j] = left[i - 1][j]
            left[i][ord(s[i]) - ord("a")] += 1
        for i in range(n, 0, -1):
            for j in range(26):
                right[i][j] = right[i + 1][j]
            right[i][ord(s[i]) - ord("a")] += 1
        st = set()
        for i in range(2, n):
            for j in range(26):
                if left[i - 1][j] != 0 and right[i + 1][j] != 0:
                    st.add(str(j) + s[i])
        return len(st)
class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        col_sum = [sum(col) - 1 for col in zip(*grid)]
        row_sum = [sum(row) - 1 for row in grid]
        m = len(grid)
        n = len(grid[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ans += col_sum[j] * row_sum[i]
        return ans

class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for x1, y1 in points:
            cnt = defaultdict(int)
            for x2, y2 in points:
                d = (x1 - x2) ** 2 + (y1 - y2) ** 2
                cnt[d] += 1
            for v in cnt.values():
                ans += (v - 1) * v
        return ans