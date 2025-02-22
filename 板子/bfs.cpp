#include <iostream>
#include <vector>
#include <queue>
typedef std::pair<int, int> PI;
std::queue<std::pair<PI, int>> que;
std::vector<std::vector<int>> g;
int n, m;
std::vector<int> dx = {1, -1, 0, 0};
std::vector<int> dy = {0, 0, -1, 1};
int ans = INT32_MAX;
void solve(){
    que.push({{0, 0}, 0});
    g[0][0] = 1;
    while(que.size()){
        auto p = que.front().first;
        int x = p.first, y = p.second;
        int d = que.front().second;
        if(x == n - 1 && y == m - 1){
            ans = std::min(ans, d);
        }
        que.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != 1){
                g[nx][ny] = 1;
                que.push({{nx, ny}, d + 1});
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < n; i++){
        g[i].resize(m);
        for(int j = 0; j < m; j++){
            std::cin >> g[i][j];
        }
    }
    solve();
    std::cout << ans;
}