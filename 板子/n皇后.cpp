#include <iostream>
#include <vector>
#include <string>
std::vector<std::string> g;
int n;
bool check(int x, int y){
    for(int i = 0; i < x; i++){
        if(g[i][y] == 'Q') return false;
    }
    for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
        if(g[i][j] == 'Q') return false;
    }
    for(int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++){
        if(g[i][j] == 'Q') return false;
    }
    return true;
}
void dfs(int x){
    if(x == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                std::cout << g[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(check(x, i)){
            g[x][i] = 'Q';
            dfs(x + 1);
            g[x][i] = '.'; 
        }
        
    }
}
int main(){
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::string t = "";
        for(int j = 0; j < n; j++) t.push_back('.');
        g.push_back(t);
    }
    dfs(0);
    return 0;
}