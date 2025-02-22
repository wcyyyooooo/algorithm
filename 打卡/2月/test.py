import cache
class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        n = len(grid)
        m = len(grid[0])
        if (m + n) % 2 == 0 or grid[0][0] == ')' or grid[n - 1][m - 1] == '(':
            return False
        @cache
        def dfs(x : int, y : int, c : int):
            if c > m + n - x - y - 1: return False
            if x == n - 1 and y == m - 1: return c == 1
            c += 1 if grid[x][y] == '(' else -1
            l = (x < n - 1 and dfs(x + 1, y, c))
            r = (y < m - 1 and dfs(x, y + 1, c))
            return c >= 0 and (l or r)
        return dfs(0, 0, 0)
class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        n = len(fruits)
        @cache
        def dfs1(i : int, j : int) -> int:
            if i < n and i < j < n:
                return max(dfs1(i + 1, j), dfs1(i + 1, j + 1), dfs1(i + 1, j - 1)) + fruits[i][j]
            return 0
        @cache
        def dfs2(i : int, j : int) -> int:
            if j < n and j < i < n:
                return max(dfs2(i, j + 1), dfs2(i - 1, j + 1), dfs2(i + 1, j + 1)) + fruits[i][j]
            return 0
        return dfs1(0, n - 1) + dfs2(n - 1, 0) + sum(fruits[i][i] for i in range(n))
    
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        @cache
        def dfs(i : int, j : int, k : int) -> int:
            if i == m or j < 0 or j >= n or k < 0 or k >= n:
                return 0
            return max(dfs(i + 1, j2, k2) for j2 in (j - 1, j , j + 1) for k2 in (k - 1, k, k + 1)) + grid[i][j] + (grid[i][k] if k != j else 0)
        return dfs(0, 0, n - 1)
    