#include <iostream>
#include <algorithm>
#include <vector>
int n;
std::vector<int> h;
void solve(){
    std::cin >> n;
    h.resize(n);
    for(int i = 0; i < n; i++) std::cin >> h[i];
    std::vector<int> dp(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(h[i] > h[j]){
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    std::cout << *std::max_element(dp.begin(), dp.end());
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}