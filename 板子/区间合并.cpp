#include <iostream>
#include <algorithm>
#include <vector>
struct node{
    int l;
    int r;
    bool operator<(const node &t){
        return l < t.l;
    }
};
int n;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    std::vector<node> s(n);
    for(int i = 0; i < n; i++){
        int l, r;
        std::cin >> l >> r;
        s[i] = {l, r};
    }
    std::sort(s.begin(), s.end());
    int cnt = 0;
    int last = s[0].r;
    for(int i = 1; i < n; i++){
        if(last < s[i].l){
            cnt ++;
        }
        last = std::max(last, s[i].r);
    }
    std::cout << cnt;
    return 0;
}