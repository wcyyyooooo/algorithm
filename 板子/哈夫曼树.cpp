#include <iostream>
#include <vector>
#include <queue>
std::priority_queue<int, std::vector<int>, std::greater<int>> que;
int n;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int v;
        std::cin >> v;
        que.push(v);
    }
    int ans = 0;
    while(que.size() != 1){
        int a = que.top(); que.pop();
        int b = que.top(); que.pop();
        que.push(a + b);
        ans += a + b;
    }   
    std::cout << ans;
}