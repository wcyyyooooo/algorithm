#include <iostream>
#include <cmath>
int n;
void solve(){
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int v;
        std::cin >> v;
        int x = (int)sqrt(v);
        for(int j = 2; j <= x; j++){
            if(v % j == 0){
                int cnt = 0;
                while(v > 1 && v % j == 0){
                    cnt += 1;
                    v /= j;
                }   
                std::cout << j << " " << cnt << "\n"; 
            }
            if(v == 1) break;
        }
        if(v > 1){
            std::cout << v << " 1\n";
        }
        std::cout << "\n";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}