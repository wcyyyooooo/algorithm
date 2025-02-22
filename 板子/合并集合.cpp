#include <iostream>
#include <vector>
std::vector<int> p;
int find(int i){
    if(p[i] != i) p[i] = find(p[i]);
    return p[i];
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, q;
    std::cin >> n >> q;
    p.resize(n + 1);
    for(int i = 0; i <= n; i++) p[i] = i;
    for(int i = 0; i < q; i++){
        char op;
        int a, b;
        std::cin >> op >> a >> b;
        int pa = find(a);
        int pb = find(b);
        if(op == 'M'){
            if(pa != pb) p[pb] = pa;
        }else{
            if(pa == pb) std::cout << "Yes\n";
            else std::cout << "No\n";
        }
    }
    return 0;
}