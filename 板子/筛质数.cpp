#include <iostream>
#include <vector>
std::vector<int> p;
std::vector<int> st;
int n;
void get_prime(int n){
    st.resize(n + 1);
    for(int i = 1; i <= n; i++) st[i] = false;
    for(int i = 2; i <= n; i++){
        if(!st[i]) p.push_back(i);
        for(int j = 0; j < p.size() && i * p[j] <= n; j++){
            st[i * p[j]] ++;
            if(i % p[j] == 0) break;
        }
    }
    std::cout << p.size();
}

int main(){
    std::cin >> n;
    get_prime(n);
}