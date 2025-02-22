#include <iostream>
#include <queue>
typedef std::pair<int, int> PI;
std::vector<std::priority_queue<PI, std::vector<PI>, std::greater<PI>>> que;
std::vector<int> s;
int n, m;
int a, b, c, d;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    s.resize(n + 1);
    que.resize(n + 1);
    for(int i = 1; i <= n; i++) std::cin >> s[i];
    for(int i = 0; i < m; i++){
        std::cin >> a >> b >> c >> d;
        while(!que[b].empty() && que[b].top().first <= a){
            s[b] += que[b].top().second;
            que[b].pop();
        }
        if(s[b] < d){
            std::cout << "-1\n";
        }else{
            que[b].push(std::make_pair(a + c, d));
            s[b] -= d;
            std::cout << s[b] << std::endl;
        }
    }
}