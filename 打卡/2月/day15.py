from collections import defaultdict
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        g = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                g[i][j] = mat[i - 1][j - 1] + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                i1 = max(i - k, 1)
                i2 = min(i + k, m)
                j1, j2 = max(j - k, 1), min(j + k, n)
                mat[i - 1][j - 1] = g[i2][j2] - g[i1 - 1][j2] - g[i2][j1 - 1] + g[i1 - 1][j1 - 1]
        return mat 
class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        g = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                g[i][j] += g[i - 1][j] + g[i][j - 1] + grid[i - 1][j - 1] - g[i - 1][j - 1]
        ans = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if g[i][j] - g[1][j - 1] - g[i - 1][1] - g[0][0] <= k:
                    ans += 1
        return ans
class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        g = [[[0] * 2 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                g[i][j][0] = g[i - 1][j][0] + g[i][j - 1][0] - g[i - 1][j - 1][0] + (grid[i - 1][j - 1] == 'X')
                g[i][j][1] = g[i - 1][j][1] + g[i][j - 1][1] - g[i - 1][j - 1][1] + (grid[i - 1][j - 1] == 'Y')
        ans = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if g[i][j][0] != 0 and g[i][j][0] == g[i][j][1]:
                    ans += 1
        return ans
            
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        g = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + mat[i - 1][j - 1]
        def check(k: int) -> bool:
            for i in range(k, m + 1):
                for j in range(k, n + 1):
                    if g[i][j] - g[i - k][j] - g[i][j - k] + g[i - k][j - k] <= threshold:
                        return True
            return False
        l, r = 0, min(m, n)
        while l < r:
            mid = (l + r + 1) // 2
            if not check(mid):
                r = mid - 1
            else:
                l = mid
        return l

class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        g = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + mat[i - 1][j - 1]
        ans = 0
        for k in range(1, min(n, m) + 1):
            for i in range(k, m + 1):
                for j in range(k, n + 1):
                    if g[i][j] - g[i - k][j] - g[i][j - k] + g[i - k][j - k] == k * k:
                        ans += 1
        return ans
        
                