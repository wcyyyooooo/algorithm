#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<int, int>>> dp(m);
        int MOD = 1e9 + 7;
        for(int i = 0; i < m; i++) dp[i].resize(n);
        dp[m - 1][n - 1].first = 0;
        dp[m - 1][n - 1].second = 1;
        for(int i = n - 2; i >= 0; i--){
            if(board[m - 1][i] == 'X')dp[m - 1][i] = {0, 0};
            else{
                if(dp[m - 1][i + 1].second != 0) dp[m - 1][i] = {dp[m - 1][i + 1].first + (board[m - 1][i] - '0'), dp[m - 1][i + 1].second};
                else dp[m - 1][i] = {0, 0};
            }
        }
        for(int i = m - 2; i >= 0; i--){
            if(board[i][n - 1] == 'X') dp[i][n - 1] = {0, 0};
            else{
                if(dp[i + 1][n - 1].second != 0) dp[i][n - 1] = {dp[i + 1][n - 1].first + (board[i][n - 1] - '0'), dp[i + 1][n - 1].second};
                else dp[i][n - 1] = {0, 0};
            }
        }
        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                if(board[i][j] == 'X') {dp[i][j] = {0, 0};continue;}
                int mx = INT32_MIN;
                int cnt = 0;
                if(dp[i + 1][j].second){
                    mx = max(mx, dp[i + 1][j].first);
                }
                if(dp[i][j + 1].second){
                    mx = max(mx, dp[i][j + 1].first);
                }
                if(dp[i + 1][j + 1].second){
                    mx = max(mx, dp[i + 1][j + 1].first);
                }
                if(mx == dp[i][j + 1].first) cnt = (cnt + dp[i][j + 1].second) % MOD;
                if(mx == dp[i + 1][j].first) cnt = (cnt + dp[i + 1][j].second) % MOD;
                if(mx == dp[i + 1][j + 1].first) cnt = (cnt + dp[i + 1][j + 1].second) % MOD;
                if(board[i][j] == 'E'){
                    if(mx != INT32_MIN) return {mx, cnt};
                    else return {0, 0};
                }else{
                    if(mx != INT32_MIN) dp[i][j] = {mx + (board[i][j] - '0'), cnt};
                    else dp[i][j] = {0, 0};
                }
            }
        }
        return {0, 0};
    }
};
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m);
        for(int i = 0; i < m; i++){
            dp[i].resize(n);
            for(int j = 0; j < n; j++) dp[i][j].resize(k);
        }
        dp[0][0][grid[0][0] % k] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 0; j < k; j++){
                dp[i][0][(j + grid[i][0]) % k] += dp[i - 1][0][j];
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < k; j++){
                dp[0][i][(j + grid[0][i]) % k] += dp[0][i - 1][j];
            }
        }
        const int MOD = 1e9 + 7;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                for(int m = 0; m < k; m ++){
                    dp[i][j][(m + grid[i][j]) % k] = (dp[i][j][(m + grid[i][j]) % k] + dp[i - 1][j][m] + dp[i][j - 1][m]) % MOD;
                }
            }            
        }
        return dp[m - 1][n - 1][0];
    }
};