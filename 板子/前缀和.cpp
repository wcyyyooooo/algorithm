#include <iostream>
#include <vector>
int n;
int m;
int main(){
    std::cin >> n >> m;
    std::vector<int> v(n + 1);
    for(int i = 0; i < n; i++){
        int val;
        std::cin >> val;
        v[i + 1] = v[i] + val;
    }
    for(int i = 0; i < m; i++){
        int l, r;
        std::cin >> l >> r;
        std::cout << v[r] - v[l - 1] << std::endl;
    }
    return 0;
}