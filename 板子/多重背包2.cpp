#include <iostream>
#include <vector>
typedef std::pair<int, int> PI;
std::vector<PI> goods;
int n, m;
std::vector<int> s, v, w;
std::vector<int> dp;
void solve(){
    std::cin >> n >> m;
    s.resize(n); v.resize(n); w.resize(n);
    dp.resize(m + 1);
    for(int i = 0; i < n; i++) std::cin >> v[i] >> w[i] >> s[i];
    for(int i = 0; i < n; i++){
        for(int k = 1; k <= s[i]; k *= 2){
            s[i] -= k;
            goods.push_back({k * v[i], k * w[i]});
        }
        if(s[i]) goods.push_back({s[i] * v[i], s[i] * w[i]});
    }
    for(int i = 0; i < goods.size(); i++){
        for(int j = m; j >= goods[i].first; j --){
            dp[j] = std::max(dp[j], dp[j - goods[i].first] + goods[i].second);
        }
    }
    std::cout << dp[m];
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}