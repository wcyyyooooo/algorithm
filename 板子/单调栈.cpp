#include <iostream>
#include <stack>
int n;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    std::stack<int> st;
    for(int i = 0; i < n; i++){
        int val;
        std::cin >> val;
        while(!st.empty() && st.top() >= val) st.pop();
        if(st.empty()) std::cout << "-1 ";
        else std::cout << st.top() << " ";
        st.push(val);
    }
    return 0;
}
