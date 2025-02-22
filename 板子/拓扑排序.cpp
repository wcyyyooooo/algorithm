#include <iostream>
#include <vector>
#include <queue>
std::vector<std::vector<int>> g;
std::vector<int> in;
int n, m;
void solve(){
    std::queue<int> que;
    std::vector<int> path;
    for(int i = 1; i <= n; i++){
        if(!in[i]) que.push(i);
    }
    while(que.size()){
        int t = que.front();
        que.pop();
        path.push_back(t);
        for(auto nxt : g[t]){
            in[nxt] --;
            if(!in[nxt]) que.push(nxt);
        }
    }
    if(path.size() == n){
        for(auto x : path) std::cout << x << " ";
    }else std::cout << "-1";
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    g.resize(n + 1);
    in.resize(n + 1);
    for(int i = 1; i <= m; i++){
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        in[b] ++;
    }
    solve();
}