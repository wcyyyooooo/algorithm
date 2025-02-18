#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(); int m = word2.size();
        word1.insert(word1.begin(), ' '); word2.insert(word2.begin(), ' ');
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) dp[i].resize(m + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i] == word2[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n + m - 2 * dp[n][m];
    }
};
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); int m = nums2.size();
        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) dp[i].resize(m + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(nums1[i] == nums2[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); int m = nums2.size();
        nums1.insert(nums1.begin(), 0); nums2.insert(nums2.begin(), 0);
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++){
            dp[i].resize(m + 1);
            for(int j = 0; j <= m; j++) dp[i][j] = INT32_MIN;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int v = nums1[i] * nums2[j];
                dp[i][j] = max(dp[i - 1][j - 1] + v, max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[n][m];
    }
};
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(); int m = str2.size();
        str1 = " " + str1; str2 = " " + str2;
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) dp[i].resize(m + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i] == str2[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans = "";
        int i = n; int j = m;
        while(i > 0 || j > 0){
            if(i == 0) ans.push_back(str2[j--]);
            else if(j == 0) ans.push_back(str1[i--]);
            else{
                if(str1[i] == str2[j]){
                    ans.push_back(str1[i]);
                    i--; j--;
                }else if(dp[i][j] == dp[i - 1][j]){
                    ans.push_back(str1[i--]);
                }else ans.push_back(str2[j--]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size(); int m = pattern.size();
        source = " " + source;
        pattern = " " + pattern;
        unordered_set<int> st(targetIndices.begin(), targetIndices.end());
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) {dp[i].resize(m + 1); for(int j = 0; j <= m; j++) dp[i][j] = INT32_MIN;}
        for(int i = 1; i <= n; i++){
            int exist = st.count(i - 1);
            dp[i][0] = dp[i - 1][0] + exist;
            for(int j = 1; j <= min(i, m); j++){
                dp[i][j] = dp[i - 1][j] + exist;
                if(source[i] == pattern[j]){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};