#include <iostream>
#include <vector>
#include <functional>
std::vector<std::vector<int>> g;
std::vector<int> color;
int n, m;
void solve(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    g.resize(n + 1);
    color.resize(n + 1);
    for(int i = 1; i <= n; i++) color[i] = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    std::function<bool(int, int)> dfs = [&](int u, int c) -> bool{
        color[u] = c;
        for(int v : g[u]){
            if(!color[v]){
                if(!dfs(v, 3 - c)) return false;
            }else if(color[v] && color[v] != 3 - c) return false;
        }
        return true;
    };
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            if(!dfs(i, 1)){
                std::cout << "No";
                return;
            }
        }
    }
    std::cout << "Yes";
}
int main(){
    solve();
}