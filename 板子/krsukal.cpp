#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> p;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
struct edge{
    int u;
    int v;
    int w;
    bool operator<(const edge&e){
        return w < e.w;
    }
};
std::vector<edge> g;
int n, m;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    p.resize(n + 1);
    g.resize(n + 1);
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        g.push_back({a, b, c});
    }
    sort(g.begin(), g.end());
    int res = 0;
    int cnt = 1;
    for(auto e : g){
        int pa = find(e.u);
        int pb = find(e.v);
        if(pa != pb){
            p[pb] = pa;
            res += e.w;
            cnt += 1;
        } 
    }
    if(cnt == n) std::cout << res;
    else std::cout << "impossible";
}