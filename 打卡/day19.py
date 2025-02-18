import heapq
from collections import defaultdict
import math
from sortedcontainers import SortedList
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)
        while len(stones) >= 2:
            a, b = -heapq.heappop(stones), -heapq.heappop(stones)
            heapq.heappush(stones, b - a)
        return -stones[0]
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        h = [[v, i] for i, v in enumerate(nums)]
        heapq.heapify(h)
        while k:
            a = heapq.heappop(h)
            heapq.heappush(h, [a[0] * multiplier, a[1]])
            k -= 1
        for hi in h:
            nums[hi[1]] = hi[0]
        return nums 
class SmallestInfiniteSet:

    def __init__(self):
        self.h = [i for i in range(1, 1001)]
        self.mp = defaultdict(int)
        for i in range(1, 1001):
            self.mp[i] = 1
    def popSmallest(self) -> int:
        v =  heapq.heappop(self.h)
        self.mp[v] = 0
        return v

    def addBack(self, num: int) -> None:
        if self.mp[num] != 1:
            heapq.heappush(self.h, num)
            self.mp[num] = 1
class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        nums = [-num for num in nums]
        heapq.heapify(nums)
        ans = 0
        while k:
            v = -heapq.heappop(nums)
            ans += v
            heapq.heappush(nums, -math.ceil(v / 3))
            k -= 1
        return ans
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        ans = 0
        while len(nums) >= 2:
            a = heapq.heappop(nums)
            b = heapq.heappop(nums)
            if a >= k:
                break
            heapq.heappush(nums, (2 * min(a, b) + max(a, b)))
            ans += 1
        return ans
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        piles = [-pile for pile in piles]
        heapq.heapify(piles)
        while k:
            v = -heapq.heappop(piles)
            heapq.heappush(piles, -math.floor(v / 2))
            k -= 1
        return sum(piles)
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.s = SortedList()
        for num in nums:
            self.s.add(-num)

    def add(self, val: int) -> int:
        self.s.add(-val)
        return -self.s[self.k - 1]
class Solution:
    def resultsArray(self, queries: List[List[int]], k: int) -> List[int]:
        s = SortedList()
        ans = []
        for query in queries:
            dis = abs(query[0]) + abs(query[1])
            s.add(dis)
            if len(s) >= k:
                ans.append(s[k - 1])
            else: ans.append(-1)
        return ans

class SeatManager:

    def __init__(self, n: int):
        self.seat = [i for i in range(1, n + 1)]
        heapq.heapify(self.seat)

    def reserve(self) -> int:
        return heapq.heappop(self.seat)
    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.seat, seatNumber)
class Solution:
    def halveArray(self, nums: List[int]) -> int:
        s = sum(nums)
        cur = sum(nums)
        ans = 0
        nums = [-num for num in nums]
        heapq.heapify(nums)
        while True:
            a = -heapq.heappop(nums)
            cur -= a
            cur += a / 2
            heapq.heappush(nums, -(a / 2))
            ans += 1
            if cur <= s / 2:
                break
        return ans
class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        while k:
            a = heapq.heappop(nums)
            heapq.heappush(a + 1)
            k -= 1
        ans = 1
        for num in nums:
            ans = (ans * num) % int(1e9 + 7)
        return ans
class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        h = [(t, t, 1) for t in workerTimes]
        heapq.heapify(h)
        ans = 0
        while mountainHeight > 0:
            a, b, c = heapq.heappop(h)
            mountainHeight -= 1
            ans = max(ans, a)
            c += 1
            a += b * c
            heapq.heappush(h, (a, b, c))
        return ans
class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        cnt = []
        for time, i in enumerate(times):
            cnt.append([time[0], i, 1])
            cnt.append([time[1], i, -1])
        cnt.sort()
        h = [i for i in range(len(times))]
        seat = defaultdict(int)
        for ci in cnt:
            if ci[2] == 1:
                v = heapq.heappop(h)
                if ci[1] == targetFriend:
                    return v
                seat[ci[1]] = v
            else:
                heapq.heappush(h, seat[ci[1]])
                ci[1] = 0
        return -1
class Solution:
    def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
        buy = []
        sell = []
        for order in orders:
            if order[2] == 1:
                if len(buy) == 0: heapq.heappush(sell, [order[0], order[1]])
                else:
                    while len(buy) > 0 and -buy[0][0] >= order[0] and order[1] > 0:
                        t = heapq.heappop(buy)
                        if t[1] > order[1]:
                            heapq.heappush(buy, [t[0], t[1] - order[1]])
                            order[1] = 0
                        else:
                            order[1] -= t[1]
                    if order[1] > 0: heapq.heappush(sell, [order[0], order[1]])
            else:
                if len(sell) == 0: heapq.heappush(buy, [-order[0], order[1]])
                else:
                    while len(sell) > 0 and sell[0][0] <= order[0] and order[1] > 0:
                        t = heapq.heappop(sell)
                        if t[1] > order[1]:
                            heapq.heappush(sell, [t[0], t[1] - order[1]])
                            order[1] = 0
                        else:
                            order[1] -= t[1]
                    if order[1] > 0:
                        heapq.heappush(buy, [-order[0], order[1]])
        ans = 0
        for t in buy:
            ans = (ans + t[1]) % int(1e9 + 7)
        for t in sell:
            ans = (ans + t[1]) % int(1e9 + 7)
        return ans
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        i = 0
        pre = []
        while i < candidates:
            pre.append(costs[i])
            i += 1
        heapq.heapify(pre)
        j = len(costs) - 1
        rear = []
        while j >= len(costs) - candidates and j >= i:
            rear.append(costs[j])
            j -= 1
        heapq.heapify(rear)
        ans = 0
        for x in range(k):
            if len(rear) == 0:
                ans += heapq.heappop(pre)
            elif len(pre) == 0:
                ans += heapq.heappop(rear)
            elif len(pre) != 0 and len(rear) != 0:
                if pre[0] < rear[0]:
                    ans += heapq.heappop(pre)
                    if i <= j:
                        heapq.heappush(pre, costs[i])
                        i += 1
                elif pre[0] > rear[0]:
                    ans += heapq.heappop(rear)
                    if j >= i:
                        heapq.heappush(rear, costs[j])
                        j -= 1
                else:
                    if costs[i] > costs[j]:
                        ans += heapq.heappop(rear)
                        if j >= i:
                            heapq.heappush(rear, costs[j])
                            j -= 1
                    else:
                        ans += heapq.heappop(pre)
                        if i <= j:
                            heapq.heappush(pre, costs[i])
                            i += 1
        return ans
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        tasks = [[task[0], task[1], i] for i, task in enumerate(tasks)]
        tasks.sort()
        h = []
        i = 0
        print(tasks)
        while i < len(tasks) and tasks[i][0] == tasks[0][0]:
            heapq.heappush(h, [tasks[i][1], tasks[i][2], tasks[i][0]])
            i += 1
        ans = []
        cur = 0
        while i < len(tasks):
            if len(h) == 0:
                heapq.heappush(h, [tasks[i][1], tasks[i][2], tasks[i][0]])
                i += 1
                while i < len(tasks) and tasks[i][0] == tasks[i - 1][0]:
                    heapq.heappush(h, [tasks[i][1], tasks[i][2], tasks[i][0]])
                    i += 1
            t = heapq.heappop(h)
            ans.append(t[1])
            cur = max(cur, t[2]) + t[0]
            while i < len(tasks) and tasks[i][0] <= cur:
                heapq.heappush(h, [tasks[i][1], tasks[i][2], tasks[i][0]])
                i += 1
        while len(h):
            t = heapq.heappop(h)
            ans.append(t[1])
        return ans  

class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.prior = defaultdict(int)
        self.taskTouser = defaultdict(int)
        self.h = []
        for task in tasks:
            self.h.append([-task[2], -task[1], -task[0]])
            self.taskTouser[task[1]] = task[0]
            self.prior[task[1]] = task[2]
        heapq.heapify(self.h)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        heapq.heappush(self.h, [-priority, -taskId, -userId])
        self.taskTouser[taskId] = userId
        self.prior[taskId] = priority
    def edit(self, taskId: int, newPriority: int) -> None:
        self.prior[taskId] = newPriority
        heapq.heappush(self.h, [-newPriority, -taskId, -self.taskTouser[taskId]])
    def rmv(self, taskId: int) -> None:
        self.prior[taskId] = -1

    def execTop(self) -> int:   
        while len(self.h):
            t = heapq.heappop(self.h)
            if -t[0] != self.prior[-t[1]]:
                continue
            if self.prior[-t[1]] == -1:
                continue
            self.prior[-t[1]] = -1
            return -t[2]
        return -1
class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        h = [[]] * len(classes)
        for i, c in enumerate(classes):
            h[i] = [(c[0] / c[1]), c[0], c[1]]
        heapq.heapify(h)
        for _ in range(extraStudents):
            _, b, c = heapq.heappop(h)
            if b >= c:
                break
            heapq.heappush(h, [(b + 1) / c, b + 1, c])
        total = 0
        pas = 0
        for hi in h:
            total += hi[2]
            pas += hi[1]
        return pas / total
class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        d = 1
        m, n = len(values), len(values[0])
        h = []
        for i in range(m):
            h.append([values[i][n - 1], i,  n - 1])
        ans = 0
        heapq.heapify(h)
        while len(h):
            t = heapq.heappop(h)
            ans += t[0] * d
            d += 1
            if t[2] == 0:
                continue
            heapq.heappush(h, [values[t[1]][t[2] - 1], t[1], t[2] - 1])
        return ans