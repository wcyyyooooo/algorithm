#include <iostream>
#include <vector>

const int M = 100003;
typedef long long LL;
LL n, m;
void solve(){
    auto cal = [](LL a, LL b) -> LL{
        std::vector<LL> c(32);
        c[0] = a;
        for(int i = 1; i < 32; i++){
            c[i] = c[i - 1] % M * c[i - 1] % M;
        }
        LL res = 1;
        for(int i = 0; i < 32; i++){
            if(b >> i & 1) res = res % M * c[i] % M;
        }
        return res;
    };
    std::cout << (cal(m, n) % M - m % M * cal(m - 1, n - 1) % M + M) % M;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    solve();
}