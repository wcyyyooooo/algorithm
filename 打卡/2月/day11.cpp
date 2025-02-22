#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i < n; i++){
            if(dp[i - 1] && nums[i] == nums[i - 1]) dp[i + 1] = true;
            if(i - 2 >= 0 && dp[i - 2] && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) dp[i + 1] = true;
            if(i - 2 >= 0 && dp[i - 2] && nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1) dp[i + 1] = true;
        }
        return dp[n];
    }
};
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        unordered_map<string, bool> st;
        for(auto &s : dictionary) st[s] = true;
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1] + 1;
            for(int j = 1; j <= i; j++){
                if(st[s.substr(j - 1, i - j + 1)]){
                    dp[i] = min(dp[i], dp[j - 1]);
                }
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    vector<string> cnt;
    void cal(){
        int i = 1;
        while(i < (1 << 15) + 1){
            string s = "";
            int c = i;
            while(c){
                s = to_string(c % 2) + s;
                c = c / 2;
            }
            i *= 5;
            cnt.push_back(s);
        }
    }
    int minimumBeautifulSubstrings(string s) {
        cal();
        unordered_map<string, bool> st;
        for(auto &t : cnt){
            st[t] = true;
        }
        int n = s.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(st[s.substr(j - 1, i - j + 1)]){
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n] < 1e9 ? dp[n] : -1;
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : 1;
        const int MOD = 1e9 + 7;
        for(int i = 1; i < n; i++){
            if((s[i] >= '0' and s[i] <= '9') and (s[i - 1] >= '0' and s[i - 1] <= '9')){
                int cur = s[i] - '0';
                int pre = s[i - 1] - '0';
                if(cur == 0){
                    if(pre == 1 or pre == 2) dp[i + 1] = dp[i - 1];
                    continue;
                }
                if(pre == 0){
                    dp[i + 1] = dp[i];
                }else{
                    if(pre * 10 + cur > 26) dp[i + 1] = dp[i];
                    else dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
                }
            }else if((s[i] >= '0' and s[i] <= '9') and s[i - 1] == '*'){
                int cur = s[i] - '0';
                if(cur == 0){
                    dp[i + 1] = (dp[i - 1] * 2) % MOD;
                    continue;
                }
                if(cur > 6){
                    dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
                }else{
                    dp[i + 1] = (dp[i] + 2 * dp[i - 1]) % MOD;
                }
            }else if((s[i - 1] >= '0' and s[i - 1] <= '9') and s[i] == '*'){
                int pre = s[i - 1] - '0';
                if(pre < 3){
                    if(pre == 0) dp[i + 1] = 9 * dp[i] % MOD;
                    else if(pre == 1) dp[i + 1] = (9 * dp[i - 1] + 9 * dp[i]) % MOD;
                    else dp[i + 1] = (6 * dp[i - 1] + 9 * dp[i]) % MOD;
                }else{
                    dp[i + 1] = 9 * dp[i] % MOD;
                }
            }else{
                dp[i + 1] = (dp[i] * 9 + 15 * dp[i - 1]) % MOD;
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = to_string(k).size();
        int m = s.size();
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        const int MOD = 1e9 + 7;
        for(int i = 0; i < m; i++){
            for(int j = i; j >= 0 && (i - j + 1) <= n; j--){
                string sub = s.substr(j, i - j + 1);
                if(sub[0] == '0') continue;
                long long x = stoll(sub);
                if(x > k) continue;
                dp[i + 1] = (dp[i + 1] + dp[j]) % MOD;
            }
        }
        return dp[m];
    }
};

class Solution {
public:
    int maxPalindromes(string s, int k) {
        if(k == 1) return s.size();
        int n = s.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for(int r = 1; r < n; r++){
            for(int l = 0; l <= r; l++){
                if(s[l] == s[r] && (r - l <= 2 or vis[l + 1][r - 1] == true)) vis[l][r] = true;
            }
        }
        vector<int> dp(n + 1);
        for(int i = 0; i < n; i++){
            dp[i + 1] = dp[i];
            for(int j = i - k + 1; j >= 0; j--){
                if(vis[j][i]){
                    dp[i + 1] = max(dp[j] + 1, dp[i + 1]);
                }
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> cnt;
            int res = 0;
            for(int j = i; j >= 0; j--){
                cnt[nums[j]] ++;
                if(cnt[nums[j]] == 2) res += 2;
                else if(cnt[nums[j]] > 2) res += 1;
                dp[i + 1] = min(dp[j] + res + k, dp[i + 1]);
            } 
        }
        return dp[n];
    }
};

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            int max_height = books[i][1];
            int s = 0;
            for(int j = i; j >= 0; j--){
                s += books[j][0];
                if(s > shelfWidth) break;
                max_height = max(max_height, books[j][1]);
                dp[i + 1] = min(dp[j] + max_height, dp[i + 1]);
            }
        }
        return dp[n];
    }
};