#include <iostream>
#include <vector>
int n;
std::vector<std::vector<int>> dp;
void solve(){
    std::cin >> n;
    dp.resize(n);
    for(int i = 0; i < n; i++){
        dp[i].resize(n);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++) std::cin >> dp[i][j];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] += dp[i - 1][j];
            else if(i == j) dp[i][j] += dp[i - 1][j - 1];
            else dp[i][j] += std::max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    int res = INT32_MIN;
    for(int i = 0; i < n; i++){
        res = std::max(res, dp[n - 1][i]);
    }
    std::cout << res;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}