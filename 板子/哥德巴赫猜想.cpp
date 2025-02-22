#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> prime;
const int N = 1e6 + 5;
void get_prime(int n){
    std::vector<bool> st(n, false);
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
    int x = 0;
    get_prime(N);
    while(x){
        std::cin >> x;
        for(int i = 0; i < prime.size(); i++){
            auto index = std::lower_bound(prime.begin(), prime.end(), x - prime[i]);
            if(index != prime.end() && *index == x - prime[i]){
                std::cout << x << " = " << prime[i] << " + " << *index << std::endl;
                break;
            }
        }
    }
    return 0;
}