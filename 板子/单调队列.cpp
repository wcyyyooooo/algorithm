#include <iostream>
#include <deque>
#include <vector>
int n, k;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> k;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    std::deque<int> que;
    for(int i = 0; i < n; i++){
        while(!que.empty() && a[que.back()] >= a[i]) que.pop_back();
        que.push_back(i);
        if(i - k >= 0 && que.front() <= i - k) que.pop_front();
        if(i - k + 1 >= 0){
            std::cout << a[que.front()] << " ";
        }
    }
    que.clear();
    std::cout << "\n";
    for(int i = 0; i < n; i++){
        while(!que.empty() && a[que.back()] <= a[i]) que.pop_back();
        que.push_back(i);
        if(i - k >= 0 && que.front() <= i - k) que.pop_front();
        if(i - k + 1 >= 0){
            std::cout << a[que.front()] << " ";
        }
    }
    return 0;
}