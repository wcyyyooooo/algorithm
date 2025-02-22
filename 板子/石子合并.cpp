#include <iostream>
#include <vector>
int n;
std::vector<int> s;
void solve(){
    std::cin >> n;
    s.resize(n + 1);
    for(int i = 1; i <= n; i++) std::cin >> s[i], s[i] += s[i - 1];
    std::vector<std::vector<int>> dp;
    dp.resize(n + 1);
    for(int i = 0; i <= n; i++) dp[i].resize(n + 1);
    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l + 1; i ++){
            int j = i + l - 1;
            dp[i][j] = 1e9 + 10;
            for(int k = i; k <= j - 1; k++){
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    std::cout << dp[1][n];
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}