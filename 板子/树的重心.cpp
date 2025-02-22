#include <iostream>
#include <vector>
std::vector<std::vector<int>> g;
int n;
int ans = INT32_MAX;
std::vector<bool> vis;
int dfs(int root){
    vis[root] = true;
    int size = 0, sum = 1;
    for(auto i : g[root]){
        if(!vis[i]){
            int s = dfs(i);
            size = std::max(size, s);
            sum += s;
        }
    }
    size = std::max(size, n - sum);
    ans = std::min(ans, size);
    return sum;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    g.resize(n + 1);
    vis.resize(n + 1);
    for(int i = 1; i <= n; i++) vis[i] = false;
    for(int i = 0; i < n - 1; i ++){
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    std::cout << ans;
}