#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        std::cin >> val;
        int cnt = 0;
        for(int j = 0; j < 32; j++){
            if(val >> j & 1){
                cnt ++;
            }
        }
        std::cout << cnt << " ";
    }
    
}