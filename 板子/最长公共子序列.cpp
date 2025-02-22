#include <iostream>
#include <vector>
#include <string>
int n, m;
void solve(){
    std::cin >> n >> m;
    std::string s1, s2;
    std::cin >> s1 >> s2;
    s1.insert(s1.begin(), ' '); s2.insert(s2.begin(), ' ');
    std::vector<std::vector<int>> dp;
    dp.resize(n + 1);
    for(int i = 0; i <= n; i++) dp[i].resize(m + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i] == s2[j]) dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
            else dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    std::cout << dp[n][m];
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}