#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> record;
int n, m;
void solve(){
    std::cin >> n >> m;
    for(int i = 0; i < n; i++){
        std::string t;
        std::cin >> t;
        t = " " + t;
        record.push_back(t);
    }
    for(int k = 0; k < m; k++){
        std::string t;
        int mx;
        std::cin >> t >> mx;
        int ans = 0;
        for(auto s : record){
            int l1 = s.size();
            int l2 = t.size();
            std::vector<std::vector<int>> dp;
            dp.resize(l1 + 1);
            for(int i = 0; i <= l1; i++) dp[i].resize(l2 + 1);
            for(int i = 0; i <= l1; i++) dp[i][0] = i;
            for(int i = 0; i <= l2; i++) dp[0][i] = i;
            for(int i = 1; i <= l1; i++){
                for(int j = 1; j <= l2; j++){
                    dp[i][j] = std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    if(s[i] == t[j]) dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
                    else dp[i][j] = std::min(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            } 
            if(dp[l1][l2] <= mx) ans ++;
        }
        std::cout << ans;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}