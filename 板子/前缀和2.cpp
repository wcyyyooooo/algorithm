#include <iostream>
#include <vector>
int n, m, q;
int main(){
    std::cin >> n >> m >> q;
    std::vector<std::vector<int>> v(n + 1);
    for(int i = 0; i <= n; i++) v[i].resize(m + 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int val;
            std::cin >> val;
            v[i + 1][j + 1] = v[i][j + 1] + v[i + 1][j] - v[i][j] + val;
        }
    }
    for(int i = 0; i < q; i++){
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1] << std::endl;
    }
    return 0;
}