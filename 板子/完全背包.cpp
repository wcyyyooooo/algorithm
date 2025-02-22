#include <iostream>
#include <vector>
std::vector<int> dp;
std::vector<int> v;
std::vector<int> w;
int n, m;
void solve(){
    std::cin >> n >> m;
    v.resize(n); w.resize(n);
    dp.resize(m + 1);
    for(int i = 0; i < n; i++) std::cin >> v[i] >> w[i];
    for(int i = 0; i < n; i++){
        for(int j = v[i]; j <= m; j++){
            dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    std::cout << dp[m];
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}