#include <iostream>
#include <vector>
#include <string>

std::vector<int> p;
std::vector<int> cnt;
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
    cnt.resize(n + 1);
    for(int i = 0; i <= n; i++) p[i] = i, cnt[i] = 1;
    for(int i = 0; i < q; i++){
        std::string op;
        int a, b;
        std::cin >> op;
        if(op == "C"){
            std::cin >> a >> b;
            int pa = find(a), pb = find(b);
            if(pa != pb){
                p[pa] = pb;
                cnt[pb] += cnt[pa];
            }
        }else if(op == "Q1"){
            std::cin >> a >> b;
            int pa = find(a), pb = find(b);
            if(pa != pb) std::cout << "No\n";
            else std::cout << "Yes\n";
        }else{
            std::cin >> a;
            std::cout << cnt[find(a)] << "\n";
        }
    }
}