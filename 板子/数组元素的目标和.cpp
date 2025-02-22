#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m, x;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m >> x;
    std::vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    for(int i = 0; i < m; i++) std::cin >> b[i];
    for(int i = 0; i < n; i++){
        int bv = x - a[i];
        auto p = std::lower_bound(b.begin(), b.end(), bv);
        if(*p == bv){
            std::cout << i << " " << p - b.begin();
            break;
        }
    }
    return 0;
}