#include <iostream>
#include <vector>
std::vector<int> path;
int n;
void dfs(int st){
    if(path.size() == n){
        for(auto it : path) std::cout << it << " ";
        std::cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!(st >> i & 1)){
            path.push_back(i);
            dfs(st + (1 << i));
            path.pop_back();
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    dfs(0);
}