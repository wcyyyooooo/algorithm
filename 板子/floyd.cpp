#include <iostream>
#include <vector>
int n, m, k;
const int MAX = 401 * 10000;
std::vector<std::vector<int>> g;
void solve(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m >> k;
    g.resize(n + 1);
    for(int i = 1; i <= n; i++){
        g[i].resize(n + 1);
        for(int j = 1; j <= n; j++) g[i][j] = MAX;
        g[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        g[a][b] = std::min(g[a][b], c);
    }
    solve();
    for(int i = 0; i < k; i++){
        int a, b;
        std::cin >> a >> b;
        if(g[a][b] >= MAX / 2){
            std::cout << "impossible\n";
        }else{
            std::cout << g[a][b] << std::endl;
        }
    }
}