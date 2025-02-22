#include <iostream>
#include <vector>
#include <map>
int main(){
    int n, res = 0;
    std::cin >> n;
    std::vector<int> v(n);
    std::map<int, int> m;
    for(int i = 0; i < n; i++) std::cin >> v[i];
    for(int i = 0, j = 0; i < n; i++){
        m[v[i]] ++;
        while(m[v[i]] > 1){
            m[v[j]] --;
            j++;
        }
        res = std::max(res, i - j + 1);
    }
    std::cout << res;
}