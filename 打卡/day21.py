class Solution:
    def sumOfGoodNumbers(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            if ((i - k >= 0 and nums[i] > nums[i - k]) or (i - k < 0)) and ((i + k >= n) or (i + k < n and nums[i] > nums[i + k])):
                ans += nums[i]
        return ans
class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        r = max(v[1] + v[2] for v in squares)
        l = 0
        total_s = 0
        for square in squares:
            total_s += square[2] * square[2]
        while r - l > 1e-5:
            mid = (l + r) / 2
            up_s = 0
            for square in squares:
                if square[1] + square[2] <= mid:
                    continue
                elif square[1] >= mid:
                    up_s += square[2]* square[2]
                else:
                    up_s += square[2] * (square[1] + square[2] - mid)
            if up_s * 2 < total_s:
                l = mid
            else:
                r = mid
        return l