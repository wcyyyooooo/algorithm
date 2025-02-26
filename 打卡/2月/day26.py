from collections import defaultdict
class Allocator:

    def __init__(self, n: int):
        self.free = [[0, n]]
        self.cnt = defaultdict(list)
    def allocate(self, size: int, mID: int) -> int:
        used = True
        st = -1
        for i in range(len(self.free)):
            if self.free[i][1] - self.free[i][0] >= size:
                st = self.free[i][0]
                self.cnt[mID].append([self.free[i][0], self.free[i][0] + size])
                self.free[i][0] += size
                used = False
                break
        if used:
            return -1
        else:
            return st
        

    def freeMemory(self, mID: int) -> int:
        s = 0
        for v in self.cnt[mID]:
            self.free.append(v)
            s += v[1] - v[0]
        t = []
        self.free = sorted(self.free)
        for f in self.free:
            if f[1] == f[0]:
                continue
            if len(t) == 0:
                t.append(f)
            else:
                if t[-1][1] != f[0]:
                    t.append(f)
                else:
                    t[-1][1] += f[1] - f[0]
        self.free = t
        self.cnt.pop(mID)
        return s