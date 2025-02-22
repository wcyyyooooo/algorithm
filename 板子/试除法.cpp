#include <iostream>
#include <vector>
#include <cmath>
int n;
void solve(){
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int v;
        std::cin >> v;
        if(v == 1){
            std::cout << "No\n";
            continue;
        }
        if(v == 2){
            std::cout << "Yes\n";
            continue;
        }
        bool found = true;
        for(int j = 2; j <= int(sqrt(v)); j++){
            if(v % j == 0){
                found = false;
                break;
            }
        }
        if(found) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}