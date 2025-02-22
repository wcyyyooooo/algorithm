#include <iostream>
#include <stack>
#include <vector>
int n;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while(true){
        std::cin >> n;
        if(!n) break;
        long long ans = 0;
        std::vector<int> h(n + 2), l(n + 2), r(n + 2);
        h[0] = -1;
        h[n + 1] = -1;
        for(int i = 1; i <= n; i++) std::cin >> h[i];
        std::stack<int> st;
        st.push(0);
        for(int i = 1; i <= n; i++){
            while(!st.empty() && h[st.top()] > h[i]) st.pop();
            l[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n + 1);
        for(int i = n; i >= 1; i--){
            while(!st.empty() && h[st.top()] > h[i]) st.pop();
            r[i] = st.top();
            st.push(i);
        }
        for(int i = 1; i <= n; i++){
            ans = std::max(ans, (long long)h[i] * (long long)(r[i] - l[i] - 1));
        }
        std::cout << ans << std::endl;
    }
}