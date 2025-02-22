#include <iostream>
#include <vector>
#include <queue>
typedef std::pair<int, int> PI;
std::vector<std::vector<PI>> g;
std::priority_queue<PI, std::vector<PI>, std::greater<PI>> que;
int n, m;
void solve(){
    std::vector<int> dis(n + 1);
    std::vector<bool> vis(n + 1);
    for(int i = 1; i <= n; i++) dis[i] = INT32_MAX, vis[i] = false;
    dis[1] = 0;
    que.push({0, 1});
    while(que.size()){
        auto it =  que.top();
        que.pop();
        int d = it.first;
        int u = it.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(auto v : g[u]){
            if(!vis[v.first] && dis[v.first] > d + v.second){
                dis[v.first] = d + v.second;
                que.push({d + v.second, v.first});
            }
        }
    }
    if(dis[n] != INT32_MAX) std::cout << dis[n];
    else std::cout << "-1";
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    g.resize(n + 1);
    for(int i = 1; i <= m; i++){
        int a, b, c;
        std::cin  >> a >> b >> c;
        g[a].push_back({b, c});
    }
    solve();
}