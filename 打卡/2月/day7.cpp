#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0) - abs(target);
        if(s % 2 or s < 0) return 0;
        s = s / 2;
        int n = nums.size();
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) dp[i].resize(s + 1);
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= s; j++){
                if(j < nums[i]) dp[i + 1][j] = dp[i][j];
                else dp[i + 1][j] = dp[i][j] + dp[i][j - nums[i]];
            }
        }
        return dp[n][s];
    }
};
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        ranges::sort(rewardValues);
        int m = rewardValues.back();
        vector<int> dp(2 * m);
        dp[0] = 1;
        int n = rewardValues.size();
        for(auto &x : rewardValues){
            for(int i = 2 * x - 1; i >= x; i--){
                if(dp[i - x]) dp[i] = dp[i - x];
            }
        }
        int res = 0;
        for(int i = 0; i < 2 * m; i++){
            if(dp[i]) res = i;
        }
        return res;
    }
};
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int s = accumulate(toppingCosts.begin(), toppingCosts.end(), 0);
        ranges::sort(toppingCosts);
        vector<pair<int, int>> ans;
        for(auto &base : baseCosts){
            int n = toppingCosts.size();
            vector<vector<int>> dp(n + 1);
            int mx = min(2 * s, target + toppingCosts[n - 1]);
            for(int i = 0; i <= n; i++){
                dp[i].resize(mx + 1);
            }
            dp[0][0] = true;
            for(int i = 0; i < n; i++){
                for(int j = 0; j <= mx; j++){
                    dp[i + 1][j] = dp[i][j];
                    for(int k = 0; k <= 2; k++){
                        if(j >= k * toppingCosts[i]) dp[i + 1][j] |= dp[i][j - k * toppingCosts[i]];
                    }
                }
            }
            vector<pair<int, int>> rec;
            for(int i = 0; i <= mx; i++){
                if(dp[n][i]) rec.push_back({abs(target - i - base), i + base});
            }
            ranges::sort(rec);
            ans.push_back(rec[0]);
        }
        ranges::sort(ans);
        return ans[0].second;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, INT32_MIN);
        dp[0] = 0;
        for(int i = 0; i < 9; i++){
            int c = cost[i];
            for(int j = c; j <= target; j++){
                dp[j] = max(dp[j], dp[j - c] + 1);
            }
        }
        if(dp[target] < 0) return "0";
        string s = "";
        for(int i = 8, j = target; i >= 0; i--){
            int c = cost[i];
            while(j >= c && dp[j] == dp[j - c] + 1){
                s += to_string(i + 1);
                j -= c;
            }
        }
        return s;
    }
};
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<int> dp(target + 1);
        dp[0] = 1;
        const int MOD = 1e9 + 7;
        for(int i = 0; i < n; i++){
            int c = types[i][0];
            int mask = types[i][1];
            for(int j = target; j >= 0; j--){
                for(int k = 0; k <= c; k++){
                    if(j < k * mask) continue;
                    dp[j] = (dp[j] + dp[j - k * mask]) % MOD;
                }
            }
        }
        return dp[target];
    }
};
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) dp[i].resize(target + 1);
        const int MOD = 1e9 + 7;
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = target; j >= 0; j--){
                for(int x = 1; x <= k; x++){
                    if(j < x) continue;
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - x]) % MOD;
                }
            }
        }
        return dp[n][target];
    }
};
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(); int n = mat[0].size();
        bitset<5000> f[2];
        f[0].set(0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                f[1] |= f[0] << mat[i][j];
            }
            f[0] = f[1];
            f[1].reset();
        }
        int ans = INT32_MAX;
        for(int i = 0; i < 5000; i++){
            if(f[0][i] && abs(i - target) < ans){
                ans = abs(i - target);
            }
        }
        return ans;
    }
};