#include <iostream>
#include <vector>
std::vector<std::vector<int>> dp;
std::vector<int> v;
std::vector<int> w;
std::vector<int> s;
int n, m;
void solve(){
    std::cin >> n >> m;
    v.resize(n + 1); w.resize(n + 1);s.resize(n + 1);
    dp.resize(n + 1);
    for(int i = 0; i <= n; i++)dp[i].resize(m + 1);
    for(int i = 1; i <= n; i++) std::cin >> v[i] >> w[i] >> s[i];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= s[i] && k * v[i] <= j; k++){
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    std::cout << dp[n][m];
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}