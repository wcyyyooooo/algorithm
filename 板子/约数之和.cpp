#include <iostream>
#include <map>
#include <cmath>
#include <functional>
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
    std::function<long long(int, int)> cal = [&](int x, int y) -> long long{
        long long res = 0;
        long long m = 1;
        for(int i = 0; i <= y; i++){
            res = (res + m) % M;
            m = m * x % M;
        }
        return res;
    };
    for(auto &[x, y] : mp){
        ans = ans * (long long)(cal(x, y)) % M;
    }
    std::cout << ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}