#include <iostream>
#include <vector>
typedef std::pair<int, int> PI;
std::vector<std::vector<int>> g;
std::vector<int> dis;
std::vector<bool> vis;
int n, m;
void solve(){
    dis[1] = 0;
    int res = 0;
    bool found = true;
    for(int i = 1; i <= n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if((t == -1 || dis[t] > dis[j]) && !vis[j]){
                t = j;
            }
        }
        vis[t] = true;
        res += dis[t];
        if(dis[t] == INT32_MAX){
            found = false;
            break;
        }
        for(int j = 1; j <= n; j++){
            dis[j] = std::min(dis[j], g[t][j]);
        }
    }
    if(found) std::cout << res;
    else std::cout << "impossible";
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    g.resize(n + 1);dis.resize(n + 1); vis.resize(n + 1);
    for(int i = 1; i <= n; i++){
        g[i].resize(n + 1);
        for(int j = 1; j <= n; j++){
            g[i][j] = INT32_MAX;
        }
        g[i][i] = 0;dis[i] = INT32_MAX;vis[i] = false;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        g[a][b] = std::min(g[a][b], c);
        g[b][a] = g[a][b];
    }
    solve();
}