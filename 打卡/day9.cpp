#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] >= nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return n - *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) left[i] = max(left[i], left[j] + 1);
            }
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j > i; j--){
                if(nums[i] > nums[j]) right[i] = max(right[i], right[j] + 1);
            }
        }
        int ans = 1;
        for(int i = 0; i < n; i++){
            if(left[i] == 1 or right[i] == 1) continue;
            ans = max(ans, left[i] + right[i] - 1);
        }
        return n - ans;
    }
};
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < k && i < n; i++){
            vector<int> rec;
            for(int j = i; j < n; j += k){
                int v = arr[j];
                int idx = (int)(lower_bound(rec.begin(), rec.end(), v + 1) - rec.begin());
                if(idx < rec.size()) rec[idx] = v;
                else rec.push_back(v);
            }
            ans += rec.size();
        }
        return n - ans;
    }
};
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> people(n);
        for(int i = 0; i < n; i++) people[i] = {scores[i], ages[i]};
        ranges::sort(people);
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(people[j].second <= people[i].second){
                    dp[i] = max(dp[j], dp[i]);
                }
            }
            dp[i] += people[i].first;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [&](const vector<int> &v1, const vector<int> &v2){
            if(v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0]; 
        });
        vector<int> height;
        for(int i = 0; i < n; i++){
            height.push_back(envelopes[i][1]);
        }
        vector<int> rec;
        for(int i = 0; i < n; i++){
            int v = height[i];
            int idx = (int)(lower_bound(rec.begin(), rec.end(), v) - rec.begin());
            if(idx < rec.size()) rec[idx] = v;
            else rec.push_back(v);
        }
        return rec.size();
    }
};
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        sort(cuboids.begin(), cuboids.end(), [&](const vector<int> &v0, const vector<int> &v1){
            if(v0[0] == v1[0]){
                if(v0[1] == v1[1]) return v0[2] < v1[2];
                else return v0[1] < v1[1];
            }
            return v0[0] < v1[0];
        });
        int n = cuboids.size();
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]){
                    dp[i] = max(dp[j], dp[i]);
                }
            }
            dp[i] += cuboids[i][0] * cuboids[i][1] * cuboids[i][2];
        }
        return *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                bool found = true;
                for(int k = 0; k < m; k++){
                    if(strs[k][i] < strs[k][j]){
                        found = false;
                        break;
                    }
                }
                if(found) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return n - *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) dp[i].resize(minProfit + 1);
        dp[0][0] = 1;
        int MOD = 1e9 + 7;
        for(int i = 0; i < n; i++){
            for(int j = n; j >= group[i]; j--){
                for(int k = minProfit; k >= 0; k--){
                    dp[j][k] = (dp[j][k] + dp[j - group[i]][max(0, k - profit[i])]);
                }
            }
        }
        return dp[n][minProfit];
    }
};