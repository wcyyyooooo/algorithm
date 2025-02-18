#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        vector<int> cnt(max_val + 1);
        for(int i = 0; i < nums.size(); i++) cnt[nums[i]]++;
        int dp0 = 0,  dp1 = cnt[1];
        for(int i = 2; i <= max_val; i++){
            int rec = dp0;
            dp0 = max(dp1, dp0);
            dp1 = rec + i * cnt[i];
        }
        return max(dp0, dp1);
    }
};
class Solution {
public:
    int countHousePlacements(int n) {
        int MOD = 1e9 + 7;
        vector<long long> f(n + 1);
        f[0] = 1, f[1] = 2;
        for(int i = 2; i <= n; i++){
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        }
        return (int)f[n] %MOD * f[n] % MOD;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        auto cal = [&](int l, int r) -> int{
            if(l >= r) return 0;
            int dp0 = 0, dp1 = nums[l];
            for(int i = l + 1; i < r; i++){
                int rec = dp0;
                dp0 = max(dp1, dp0);
                dp1 = rec + nums[i];
            }
            return max(dp0, dp1);
        };
        int n = nums.size();
        return max(nums[0] + cal(2, n - 1), cal(1, n));
    }
};
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> cnt;
        for(int i = 0; i < power.size(); i++){
            cnt[power[i]] ++;
        }
        vector<pair<int, int>> rec;
        for(auto &[k, v] : cnt) rec.push_back({k, v});
        ranges::sort(rec);
        int n = rec.size();
        vector<long long> dp(n + 1);
        for(int i = 0, j = 0; i < n; i++){
            while(rec[j].first < rec[i].first - 2) j++;
            dp[i + 1] = max(dp[i], dp[j] + (long long) rec[i].first * rec[i].second);
        }
        return dp[n];
    }
};
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> char_vals;
        for(char i = 'a'; i <= 'z'; i++) char_vals[i] = (i - 'a') + 1;
        for(int i = 0;i < chars.size(); i++) char_vals[chars[i]] = vals[i];
        int pre = 0;
        int ans = 0;
        for(char c : s){
            ans = max(ans, pre + char_vals[c]);
            pre = max(0, pre + char_vals[c]);
        }
        return ans;
    }
};
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        arr.insert(arr.begin(), 0);
        arr.push_back(0);
        int mid_mx = 0, mid_s = 0;
        for(int i = 1; i <= n; i++){
            mid_s = max(mid_s + arr[i], 0);
            mid_mx = max(mid_mx, mid_s);
        }
        int left_s = 0, right_s = 0, left_mx = 0, right_mx = 0;
        for(int i = 1; i <= n ; i++){
            left_s += arr[i];
            left_mx = max(left_mx, left_s);
        }
        for(int i = n; i >= 1; i--){
            right_s += arr[i];
            right_mx = max(right_mx, right_s);
        }
        int s = accumulate(arr.begin(), arr.end(), 0);
        int res = 0;
        int MOD = 1e9 + 7;
        if(k == 1){
            return mid_mx;
        }else if(k == 2){
            return int(max(2 * s, max(left_mx + right_mx, mid_mx)) % MOD);
        }
        return max(max(mid_mx, (int)((long long) k * (long long)s % MOD)), max((int)(((long long) (k - 2) * (long long)s + right_mx + left_mx) % MOD), left_mx + right_mx));
    }
};
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_mn = nums[0], min_s = 0, max_mx = nums[0], max_s = 0;
        for(auto num : nums){
            min_s = min(min_s, 0) + num;
            min_mn = min(min_s, min_mn);
            max_s = max(max_s, 0) + num;
            max_mx = max(max_mx, max_s);
        }
        int s = accumulate(nums.begin(), nums.end(), 0);
        if(s == min_mn) return max_mx;
        return max(max_mx, s - min_mn);
    }
};
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff(nums1.size());
        for(int i = 0; i < n; i++) diff[i] = nums1[i] - nums2[i];
        int min_s = 0, min_mn = diff[0], max_mx = diff[0], max_s = 0;
        for(int i = 0; i < n; i++){
            min_s = min(0, min_s + nums1[i]);
            min_mn = min(min_mn, min_s);
            max_s = max(0, max_s + nums1[i]);
            max_mx = max(max_mx, max_s);
        }
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        return max(s1 + max_mx, s2 - min_mn);
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++) dp[i].resize(n);
        for(int i = 0; i < n; i++) dp[0][i] = grid[0][i];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int mn = INT32_MAX;
                for(int k = 0; k < n; k++){
                    if(k != j) mn = min(mn, dp[i - 1][k]);
                }
                dp[i][j] = grid[i][j] + mn;
            }
        }      
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m);
        for(int i = 0; i < m; i++){
            dp[i].resize(n); for(int j = 0; j < n; j++) dp[i][j].resize(3);
        }
        dp[0][0][0] = coins[0][0];
        for(int i = 1; i < n; i++){
            dp[0][i][0] = coins[0][i] + dp[0][i - 1][0];
            dp[0][i][1] = max(dp[0][i - 1][0], coins[0][i] + dp[0][i - 1][1]);
            dp[0][i][2] = max(dp[0][i - 1][1], coins[0][i] + dp[0][i - 1][2]);
        }
        for(int i = 1; i < m; i++){
            dp[i][0][0] = coins[i][0] + dp[i - 1][0][0];
            dp[i][0][1] = max(coins[i][0] + dp[i - 1][0][1], dp[i - 1][0][0]);
            dp[i][0][2] = max(coins[i][0] + dp[i - 1][0][2], dp[i - 1][0][1]);
            
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];
                dp[i][j][1] = max(max(dp[i - 1][j][1], dp[i][j - 1][1]) + coins[i][j], max(dp[i - 1][j][0], dp[i][j - 1][0]));
                dp[i][j][2] = max(max(dp[i - 1][j][2], dp[i][j - 1][2]) + coins[i][j], max(dp[i - 1][j][1], dp[i][j - 1][1]));
            }
        }
        return max(max(dp[m - 1][n - 1][0], dp[m - 1][n - 1][1]), dp[m - 1][n - 1][2]);
    }
};
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<vector<long long>>> dp(m);      
        for(int i = 0; i < m; i++){
            dp[i].resize(n);
            for(int j = 0; j < n; j++) dp[i][j].resize(2);
        }
        long long MOD = 1e9 + 7;
        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = grid[0][0];
        for(int i = 1; i < m; i++){
            dp[i][0][0] = max(dp[i - 1][0][0] * grid[i][0], dp[i - 1][0][1] * grid[i][0]);
            dp[i][0][1] = min(dp[i - 1][0][0] * grid[i][0], dp[i - 1][0][1] * grid[i][0]);
        }
        for(int i = 1; i < n; i++){
            dp[0][i][0] = max(dp[0][i - 1][0] * grid[0][i], dp[0][i - 1][1] * grid[0][i]);
            dp[0][i][1] = min(dp[0][i - 1][0] * grid[0][i], dp[0][i - 1][1] * grid[0][i]);
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j][0] = max(max(dp[i - 1][j][0] * grid[i][j], dp[i - 1][j][1] * grid[i][j]), max(dp[i][j - 1][0] * grid[i][j], dp[i][j - 1][1] * grid[i][j]));
                dp[i][j][1] = min(min(dp[i - 1][j][0] * grid[i][j], dp[i - 1][j][1] * grid[i][j]), min(dp[i][j - 1][0] * grid[i][j], dp[i][j - 1][1] * grid[i][j]));
            }
        }
        if(dp[m - 1][n - 1][0] < 0) return -1;
        return (int)(dp[m - 1][n - 1][0] % MOD);
    }
}; 