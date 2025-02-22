#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;
std::vector<int> prime;
std::vector<bool> st;
int n;
void get_prime(int n){
    st.resize(n + 1);
    for(int i = 0; i <= n; i++) st[i] = false;
    for(int i = 2; i <= n; i++){
        if(!st[i]) prime.push_back(i);
        for(int j = 0; j < prime.size() && i * prime[j] <= n; j++){
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    get_prime(n + 1);
    for(int i = 2; i <= n; i++){
        if(st[i]) continue;
        LL ans = 0;
        for(LL j = i; j <= n; j *= i) ans += n / j;
        std::cout << i << " " << ans << std::endl;
    }
    return 0;
}