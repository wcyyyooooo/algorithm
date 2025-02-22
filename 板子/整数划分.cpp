#include <iostream>
#include <vector>
int n;
const int MOD = 1e9 + 7;
void solve(){
    std::cin >> n;
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j >= i) dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    std::cout << dp[n];
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}