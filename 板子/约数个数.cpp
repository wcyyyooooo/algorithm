#include <iostream>
#include <map>
#include <cmath>
int n;
const int M = 1e9 + 7;
void solve(){
    std::cin >> n;
    std::map<int, int> mp;
    while(n--){
        int v; std::cin >> v;
        int x = (int)(sqrt(v));
        for(int i = 2; i <= x; i++){
            while(v % i == 0){
                v /= i;
                mp[i] ++;
            }
        }
        if(v > 1) mp[v] += 1;
    }
    long long ans = 1;
    for(auto &[x, y] : mp){
        ans = ans * (long long)(y + 1) % M;
    }
    std::cout << ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}