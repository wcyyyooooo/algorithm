#include <iostream>
#include <vector>
typedef std::pair<int, int> PI;
std::vector<std::vector<PI>> g;
std::vector<int> s;
int n, m;
std::vector<int> dp;
void solve(){
    std::cin >> n >> m;
    s.resize(n);g.resize(n);
    dp.resize(m + 1);
    for(int i = 0; i < n; i++){
        std::cin >> s[i];
        for(int j = 0; j < s[i]; j++){
            int a, b;
            std::cin >> a >> b;
            g[i].push_back({a, b});
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = m; j >= 0; j--){
            for(int k = 0; k < s[i]; k++){
                if(j >= g[i][k].first){
                    dp[j] = std::max(dp[j], dp[j - g[i][k].first] + g[i][k].second);
                }
            }
        }
    }
    std::cout << dp[m];
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}