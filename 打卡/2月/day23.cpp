#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(numCarpets + 1, vector<int>(n + 1));
        dp[0][0] = (floor[0] == '1');
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i - 1] + (floor[i] == '1');
        }
        for(int i = 1; i <= numCarpets; i++){
            for(int j = i * carpetLen; j < n; j++){
                dp[i][j] = min(dp[i][j - 1] + (floor[j] == '1'), dp[i - 1][j - carpetLen]);
            }
        }
        return dp[numCarpets][n - 1];
    }
};