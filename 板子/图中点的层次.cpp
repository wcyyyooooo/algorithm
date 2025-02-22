#include <iostream>
#include <vector>
#include <queue>
std::vector<std::vector<int>> g;
typedef std::pair<int, int> PI;
int n, m;
int ans = INT32_MAX;
void solve(){
    std::queue<PI> que;
    std::vector<bool> vis(n + 1);
    for(int i = 1; i <= n; i++) vis[i] = false;
    que.push({1, 0});
    vis[1] = true;
    while(que.size()){
        auto p = que.front();
        que.pop();
        int u = p.first;
        int d = p.second;
        if(u == n) {ans = d; break;}
        for(auto nxt : g[u]){
            if(!vis[nxt]){
                vis[nxt] = true;
                que.push({nxt, d + 1});
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
    }
    solve();
    if(ans != INT32_MAX) std::cout << ans;
    else std::cout << -1;
}
