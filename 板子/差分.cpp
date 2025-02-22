#include <iostream>
#include <vector>
int n, m;
int main(){
    std::cin >> n >> m;
    std::vector<int> a(n + 2), b(n + 2);
    for(int i = 1; i <= n; i++){
        std::cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    for(int i = 0; i < m; i++){
        int x, y, c;
        std::cin >> x >> y >> c;
        b[x] += c;
        b[y + 1] -= c;
    }
    for(int i = 1; i <= n; i++){
        b[i] += b[i - 1];
        std::cout << b[i] << " ";
    }
}