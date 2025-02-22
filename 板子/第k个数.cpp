#include <iostream>
#include <vector>
typedef long long LL;
int n;
const int M = 200907;
void solve(){
    while(n--){
        int a, b, c, k;
        std::cin >> a >> b >> c >> k;
        if(b - a == c - b){
            int d = b - a;
            std::cout << a + (k - 1) * d << std::endl; 
        }else{
            int d = b / a;
            auto cal = [](int a, int b) -> LL{
                std::vector<LL> c(32);
                c[0] = a;
                for(int i = 1; i < 32; i++){
                    c[i] = c[i - 1] % M * c[i - 1] % M;
                }
                LL res = 1;
                for(int i = 0; i < 32; i++){
                    if(b >> i & 1) res = (res * c[i]) % M;
                }
                return res;
            };
            std::cout << a * cal(d, k - 1) % M << std::endl;
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    solve();
}