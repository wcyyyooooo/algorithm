#include <iostream>
int n;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    while(n--){
        int a, b;
        std::cin >> a >> b;
        std::cout << gcd(a, b) << std::endl;
    }
}