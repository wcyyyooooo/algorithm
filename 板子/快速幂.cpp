#include <iostream>
#include <vector>
#include <functional>
typedef long long LL;
int n;
void solve(){
    std::function<LL(int, int, int)> cal = [](int a, int b, int p) -> int{
        std::vector<LL> c(32);
        c[0] = a;
        for(int i = 1; i <= 31; i++){
            c[i] = c[i - 1] % p * c[i - 1] % p;
        }
        LL res = 1;
        for(int i = 0; i < 32; i++){
            if(b >> i & 1) res = (res * c[i]) % p;
        }
        return res;
    };
    while(n --){
        int a, b, p;
        std::cin >> a >> b >> p;
        std::cout << cal(a, b, p) << std::endl;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    solve();
}