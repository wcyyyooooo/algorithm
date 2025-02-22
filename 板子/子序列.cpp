#include <iostream>
#include <vector>

int main(){
    int n, m;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    for(int i = 0; i < m; i++) std::cin >> b[i];
    int i = 0, j = 0;
    while(i < a.size()){
        while(j < b.size() && b[j] != a[i]){
            j++;
        }
        if(i == a.size() || j == b.size()) break;
        i ++;
        j ++;
    }
    if(i == a.size()) std::cout << "Yes";
    else std::cout << "No";
    return 0;
}