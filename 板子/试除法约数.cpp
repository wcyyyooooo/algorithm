#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int n;
void solve(){
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int v;
        std::cin >> v;
        std::vector<int> rec;
        for(int j = 1; j <= (int)sqrt(v); j++){
            if(v % j == 0){
                rec.push_back(j);
                if(j != v / j){
                    rec.push_back(v / j);
                }
            }
        }
        std::sort(rec.begin(), rec.end());
        for(auto it : rec) std::cout << it << " ";
        std::cout << std::endl;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}