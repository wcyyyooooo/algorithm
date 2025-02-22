#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mx >= i) mx = max(mx, nums[i] + i);
        }
        return mx >= nums.size() - 1;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int ans = 0;
        int maxl = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            maxl = max(nums[i] + i, maxl);
            if(i == end){
                end = maxl;
                ans ++;
            }
        }      
        return ans;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> cnt;
        for(int i = 0; i < s.size(); i++){
            if(cnt.count(s[i])) cnt[s[i]].second = i;
            else cnt[s[i]] = {i, i};
        }      
        vector<pair<int, int>> rec;
        for(auto &[_, v] : cnt) rec.push_back(v);
        sort(rec.begin(), rec.end(), [&](auto v1, auto v2){return v1.first < v2.first;});
        int last = rec[0].second;
        vector<int> ans;
        int pre = 0;
        for(int i = 1; i < rec.size(); i++){
            if(rec[i].first > last) {
                ans.push_back(last - pre + 1);
                last = rec[i].second;
                pre = rec[i].first;
            }else last = max(last, rec[i].second);
        }
        ans.push_back(last - pre + 1);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        for(int i = 0; i < numRows; i++) dp[i].resize(i + 1);
        dp[0][0] = 1;
        for(int i = 1; i < numRows; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0) dp[i][j] = dp[i - 1][j];
                else if(i == j) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++) dp[i].resize(2);
        dp[0][0] = 0, dp[0][1] = nums[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for(int i = 1; i <= (int)sqrt(n) + 1; i++){
            v.push_back(i * i);
        }      
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++) dp[i] = INT32_MAX;
        dp[0] = 0;
        for(int i = 0; i < v.size(); i++){
            for(int j = v[i]; j <= n; j++){
                dp[j] = min(dp[j - v[i]] + 1, dp[j]);
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++) dp[i].resize(2);
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(nums[i], max(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]));
            dp[i][1] = min(nums[i], min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]));
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> st;
        for(auto &word : wordDict) st[word] = true;
        int n = s.size();
        s.insert(s.begin(), ' ');
        vector<bool> dp(n + 1);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(st.count(s.substr(j, i - j + 1))){
                    dp[i] = dp[j - 1] | dp[i];
                }
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) dp[i] = max(dp[j] + 1, dp[i]); 
            }
        }      
        return *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if(s % 2) return false;
        int target = s / 2;
        int n = nums.size();
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) dp[i].resize(target + 1);
        dp[0][0] = true;
        for(int i = 0; i < n; i++){
            for(int j = nums[i]; j <= target; j++){
                dp[i + 1][j] = dp[i][j] | dp[i][j - nums[i]];
            }
        }       
        return dp[n][target];
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.size()) ans = max(ans, i - st.top());
                else st.push(i);
            }
        }      
        return ans;
    }
};
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        for(int i = 0; i < m; i++) dp[i].resize(n);
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int i = 0; i < n; i++) dp[0][i] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];      
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        // vector<vector<int>> dp(m);
        // for(int i = 0; i < m; i++) dp[i].resize(n);
        for(int i = 1; i < m; i++) grid[i][0] += grid[i - 1][0];
        for(int i = 1; i < n; i++) grid[0][i] += grid[0][i - 1];
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(); int m = text2.size();
        text1 = " " + text1;
        text2 = " " + text2;
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) dp[i].resize(m + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i] == text2[j]){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }else dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i][j]);
            }
        }      
        return dp[n][m];
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(); int m = word2.size();
        word1 = " " + word1; word2 = " " + word2;
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) {
            dp[i].resize(m + 1);
            for(int j = 0; j <= m; j++) dp[i][j] = INT32_MAX;
        }
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int i = 0; i <= m; i++) dp[0][i] = i;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(word1[i] == word2[j]){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }else{
                    dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }      
        return dp[n][m];
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        int i = 0;
        while(i <= r){
            if(nums[i] == 0) swap(nums[i++], nums[l++]);
            else if(nums[i] == 1) i++;
            else swap(nums[i], nums[r--]);
        }
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) i--;
        if(i >= 0){
            int j = n - 1;
            while(j >= 0 && nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        if(i < 0){
            reverse(nums.begin(), nums.end());
        }
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1; int r = nums.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= mid) cnt++;
            }
            if(cnt > mid){
                r = mid;
            }else l = mid + 1;
        }
        return l;
    }
};