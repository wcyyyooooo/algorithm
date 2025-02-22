import heapq
from collections import defaultdict
from sortedcontainers import SortedList
import bisect
class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        q = []
        t = []
        for i, s in enumerate(servers):
            q.append([s, i])
        heapq.heapify(q)
        i = 0
        cur = 0
        ans = [0] * len(tasks)
        while i < len(tasks):
            while len(t) and t[0][0] <= i:
                x = heapq.heappop(t)
                heapq.heappush(q, [x[1], x[2]])
            if len(q) == 0:
                x = heapq.heappop(t)
                cur = max(x[0], i, cur)
                heapq.heappush(q, [x[1], x[2]])
            a = heapq.heappop(q)
            ans[i] = a[1]
            cur = max(cur, i)
            heapq.heappush(t, [cur + tasks[i], a[0], a[1]])
            i += 1
        return ans
class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        cnt = [[v[0], v[1]] for v in zip(capital, profits)]
        cnt.sort()
        hp = []
        j = 0
        for _ in range(k):
            while j < len(cnt) and cnt[j][0] <= w:
                heapq.heappush(hp, -cnt[j][1])
                j += 1
            if len(hp) == 0:
                break
            t = -heapq.heappop(hp)
            w += t
        return w
class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        ans = 0
        hp = []
        n = len(apples)
        for i in range(n):
            while len(hp) and hp[0][0] <= i:
                heapq.heappop(hp)
            if len(hp) and (apples[i] == 0 or (apples[i] != 0 and hp[0][0] < i + days[i])):
                t = heapq.heappop(hp)
                if t[1] > 1:
                    heapq.heappush(hp, [t[0], t[1] - 1])
                ans += 1
                if apples[i] > 0:
                    heapq.heappush(hp, [i + days[i], apples[i]])
            else:
                if apples[i] == 0:
                    continue
                ans += 1
                if apples[i] > 1:
                    heapq.heappush(hp, [i + days[i], apples[i] - 1])
        cur = n
        while len(hp):
            while len(hp) and hp[0][0] <= cur:
                heapq.heappop(hp)
            if len(hp) == 0:
                break
            t = heapq.heappop(hp)
            if t[1] > 1:
                heapq.heappush(hp, [t[0], t[1] - 1])
            ans += 1
            cur += 1
        return ans
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        max_time = max([v[1] for v in events])
        time = [[] for _ in range(max_time + 1)]
        hp = []
        ans = 0
        for i, v in enumerate(events):
            time[v[0]].append(i)
        for i in range(max_time + 1):
            for j in time[i]:
                heapq.heappush(hp, events[j][1])
            while len(hp) and hp[0] < i:
                heapq.heappop(hp)
            if len(hp):
                heapq.heappop(hp)
                ans += 1
        return ans
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        # max = pres + x
        s = sum(target)
        hp = [-v for v in target]
        heapq.heapify(hp)
        while hp[0] != -1:
            t = -heapq.heappop(hp)
            pre_s = s - t
            if t - pre_s < 1 or pre_s == 0:
                return False
            cur_t = 1 if pre_s == 1 else t % pre_s
            s = pre_s + cur_t
            if cur_t == 0:
                return False
            heapq.heappush(hp, -cur_t)
        return True
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(endTime, startTime, profit))
        ans = 0
        dp = [0] * (len(jobs) + 1)
        for i, (_, st, p) in enumerate(jobs):
            j = bisect.bisect_left(jobs, (st + 1, ), hi = i)
            dp[i + 1] = max(dp[i], dp[j] + p)
        return dp[-1]
class RangeFreqQuery:
    def __init__(self, arr: List[int]):
        self.g = defaultdict(list)
        for i, v in enumerate(arr):
            self.g[v].append(i)
    def query(self, left: int, right: int, value: int) -> int:
        return bisect.bisect_right(self.g[value], right) - bisect.bisect_left(self.g[value], left)
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        a = []
        for i in range(len(nums)):
            for v in nums[i]:
                a.append([v, i])
        a.sort()
        cnt = defaultdict(int)
        n = len(a)
        j = 0
        min_len = 0
        min_l, min_r = 0, 0
        for i in range(n):
            cnt[a[i][1]] += 1
            while cnt[a[j][1]] > 1:
                cnt[a[j][1]] -= 1
                j += 1
            if len(cnt) == len(nums):
                if a[i][0] - a[j][0] < min_len:
                    min_len = a[i][0] - a[j][0]
                    min_l, min_r = a[j][0], a[i][0]
        return [min_l, min_r]
class Solution:
    def strWithout3a3b(self, a: int, b: int) -> str:
        ans = ''
        while a > 0 and b > 0:
            if a > b:
                ans += 'aa' + 'b'
                a -= 2
                b -= 1
            elif a < b:
                ans += 'bb' + 'a'
                b -= 2
                a -= 1
            else:
                ans += 'a' + 'b'
                a, b = a - 1, b - 1
        ans += 'a' * a + 'b' * b
        return ans