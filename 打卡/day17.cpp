#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int pre = 0;
        vector<string> ans;
        for(auto &v : target){
            if(v - pre == 1){
                ans.push_back("Push");
            }else{
                for(int i = 0; i < v - pre - 1; i++){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
                ans.push_back("Push");
            }
            pre = v;
        }    
        return ans;  
    }
};
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        auto cal = [&](string &s){
            string ans = "";
            for(auto c : s){
                if(c == '#'){
                    if(!ans.size()) continue;
                   ans.pop_back(); 
                }
                else ans.push_back(c);
            }
            return ans;
        };
        return cal(s) == cal(t);
    }
};
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> cnt;
        for(auto &op : operations){
            if(op == "C"){
                cnt.pop_back();
            }else if(op == "D"){
                cnt.push_back(cnt[cnt.size() - 1] * 2);
            }else if(op == "+"){
                cnt.push_back(cnt[cnt.size() - 1] + cnt[cnt.size() - 2]);
            }else{
                cnt.push_back(stoi(op));
            }
        }      
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};
class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto &c : s){
            if(c == '*') ans.pop_back();
            else ans.push_back(c);
        }      
        return ans;
    }
};
class BrowserHistory {
public:
    vector<string> cnt;
    int cur = -1;
    BrowserHistory(string homepage) {
        cnt.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        cnt.erase(cnt.begin() + cur + 1, cnt.end());
        cnt.push_back(url);
        cur = cnt.size() - 1;
    }
    
    string back(int steps) {
        cur = max(cur - steps, 0);
        return cnt[cur];
    }
    
    string forward(int steps) {
        cur = min(cur + steps, (int)cnt.size() - 1);
        return cnt[cur];
    }
};
class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<char, char> mp;
        unordered_map<char, vector<int>> cnt;
        for(int i = 0; i < 26; i++){
            mp['a' + i] = 'a' + 25 - i;
        } 
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(cnt.contains(mp[c]) && cnt[mp[c]].size()){
                ans += i - cnt[mp[c]].back();
                cnt[mp[c]].pop_back();
            }
            cnt[c].push_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    string clearStars(string s) {
        string ans = "";
        vector<bool> used(s.size(), true);
        unordered_map<int, vector<int>> cnt;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                int del = -1;
                for(int j = 0; j < 26; j++){
                    if(cnt[j].size()){
                        del = cnt[j].back();
                        cnt[j].pop_back();
                        break;
                    }
                }
                if(del != -1) used[del] = false;
            }else cnt[(s[i] - 'a')].push_back(i);
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*' and used[i]) ans.push_back(s[i]);
        }
        return ans;
    }
};
class CustomStack {
public:
    vector<int> st;
    int mx = 0;
    CustomStack(int maxSize) {
       mx = maxSize; 
    }
    
    void push(int x) {
        if(st.size() < mx) st.push_back(x);
    }
    
    int pop() {
        if(!st.size()) return -1;
        int v = st.back();
        st.pop_back();
        return v;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, (int)st.size()); i++){
            st[i] += val;
        }
    }
};
class FreqStack {
public:
    unordered_map<int, int> mp;
    vector<vector<int>> st;
    FreqStack() {
        
    }
    
    void push(int val) {
        if(mp[val] == st.size()){
            st.push_back({val});
        }else{
            st[mp[val]].push_back(val);
        }
        mp[val] += 1;
    }
    
    int pop() {
        int v = st.back().back();
        st.back().pop_back();
        if(st.back().size() == 0) st.pop_back();
        mp[v] -= 1;
        return v;
    }
};
class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        for(auto &c : s){
            if(!st.empty() && st.back() == c){
                st.pop_back();
            }else{
                st.push_back(c);
            }
        }
        string ans = "";
        for(auto &c : st) ans.push_back(c);
        return ans;
    }
};
class Solution {
public:
    string makeGood(string s) {
        vector<char> st;
        for(auto &c : s){
            if(st.size() && ((c >= 'A' && c <= 'Z' && (c - 'A' == st.back() - 'a')) || (c >= 'a' && c <= 'z' && (c - 'a' == st.back() - 'A')))){
                st.pop_back();
            }else st.push_back(c);
        }
        string ans = "";
        for(auto &c : st) ans.push_back(c);
        return ans;
    }
};
class Solution {
public:
    bool isValid(string s) {
        vector<int> st;
        for(auto &c : s){
            int n = st.size();
            if(n >= 2 && c == 'c' && st[n - 1] == 'b' && st[n - 2] == 'a'){
                st.pop_back(); st.pop_back();
            }else st.push_back(c);
        }      
        return st.size() == 0;
    }
};
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        vector<int> st;
        for(int i = 0; i < nums.size(); i++){
            if(st.size() % 2 && st.back() == nums[i]) continue;
            else st.push_back(nums[i]);
        }
        return nums.size() - (st.size() / 2 * 2);
    }
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<char> st;
        auto check = [&](char &c){
            if(st.size() < k - 1) return false;
            int n = st.size();
            for(int i = n - k + 1; i < n; i++){
                if(st[i] != c) return false;
            }
            return true;
        };
        for(auto &c : s){
            if(check(c)){
                for(int i = 0; i < k - 1; i++) st.pop_back();
            }else st.push_back(c);
        }
        string ans = "";
        for(auto &c : st) ans.push_back(c);
        return ans;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto &a : asteroids){
            if(a > 0){
                ans.push_back(a);
            }else{
                bool exist = true;
                while(ans.size()){
                    if(ans.back() > 0){
                        if(abs(ans.back()) > abs(a)){
                            exist = false;
                            break;
                        }
                        else if(abs(ans.back()) == abs(a)){
                            exist = false;
                            ans.pop_back();
                            break;
                        }else ans.pop_back();
                    }else break;
                }
                if(exist) ans.push_back(a);
            }
        }      
        return ans;
    }
};
class Solution {
    public:
        int maximumGain(string s, int x, int y) {
            auto cal = [&](char a, char b, int v1, int v2){
                int res = 0;
                int c1 = 0, c2 = 0;
                for(auto &c : s){
                    if(c == a){
                        c1 += 1;
                    }else if(c == b){
                        if(c1 == 0) c2 ++;
                        else res += v1, c1 --;
                    }else{
                        res += v2 * min(c1, c2);
                        c1 = 0, c2 = 0;
                    }
                }
                return res;
            };
            if(x > y) return cal('a', 'b', x, y);
            return cal('b','a', y, x);
        }
    };
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        function<int(int, int)> gcd = [&](int a, int b){
            if(b == 0) return a;
            return gcd(b, a % b);
        };
        vector<int> st;
        for(auto &num : nums){
            if(st.size()){
                while(st.size()){
                    int v = gcd(st.back(), num);
                    int l = (long long)num * (long long)st.back() / v;
                    if(v > 1){
                        num = l;
                        st.pop_back();
                        if(st.size() == 0) {st.push_back(num); break;}
                    }else{
                        st.push_back(num);
                        break;
                    }
                }
            }else st.push_back(num);
        }
        return st;
    }
};
class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> st;
        for(auto &c : s){
            if(st.size() && st.back() == '(' && c == ')'){
                st.pop_back();
            }else st.push_back(c);
        }      
        return st.size();
    }
};
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        vector<char> st;
        for(auto &c : s){
            if(c == ')') st.pop_back();
            if(st.size()) res.push_back(c);
            if(c == '(') st.push_back(c);
        }
        return res;
    }
};
class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        vector<char> st;
        for(auto &c : s){
            if(c == '(') st.push_back(c);
            else if(c == ')') st.pop_back();
            mx = max(mx, (int)st.size());
        }      
        return mx;
    }
};
class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> st;
        for(auto &c : s){
            if(c == '(') st.push_back(c);
            else if(c == ')'){
                string t = "";
                while(st.back() != '('){
                    t.push_back(st.back());
                    st.pop_back();
                }
                st.pop_back();
                for(auto &x : t) st.push_back(x); 
            }else st.push_back(c);
        }
        string ans = "";
        for(auto &c : st) ans.push_back(c);
        return ans;
    }
};
class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<char> st;
        vector<int> cnt;
        for(auto &c : s){
            if(c == '(') st.push_back(c);
            else{
                if(st.back() == '('){
                    st.pop_back();
                    st.push_back('*');
                    cnt.push_back(1);
                }else{
                    int s = 0;
                    while(st.back() != '*'){
                        st.pop_back();
                        s += cnt.back();
                        cnt.pop_back();
                    }
                    st.pop_back();
                    st.push_back('*');
                    cnt.push_back(s);
                }
            }
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0;
        string ans = "";
        int cnt = 0;
        for(auto &c : s){
            if(c == '(') left ++;
            else if(c == ')' && left) cnt ++, left --; 
        }
        left = 0;
        for(auto &c : s){
            if(c == '(' && cnt){
                ans.push_back('(');
                cnt -= 1;
                left += 1;
            }else if(c == ')' && left){
                ans.push_back(')');
                left -= 1;
            }else ans.push_back(c);
        }
        return ans;
    }
};
class Solution {
public:
    int minSwaps(string s) {
        int left = 0;
        int cnt = 0;
        for(auto &c : s){
            if(c == '[') left ++;
            else if(c == ']' && left){
                left --;
                cnt ++;
            }
        }
        return ((s.size() - 2 * cnt) / 2 + 1) / 2;
    }
};
class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        int dot = 0;
        for(auto &c : s){
            if(c == '(') left += 1;
            else if(c == ')'){
                if(left) left--;
                else{
                    if(dot == 0) return false;
                    else dot --;
                }
            }else dot ++;
        }  
        int right = 0;
        int dot1 = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ')') right ++;
            else if(s[i] == '('){
                if(right) right--;
                else{
                    if(dot1 == 0) return false;
                    else dot1 --;
                }
            }else dot1 ++;
        }
        return dot >= left and dot1 >= right;    
    }
};
class Solution {
public:
    int minInsertions(string s) {
        int left = 0;
        int right1 = 0;
        int right2 = 0;
        int i = 0;
        int ans = 0;
        while(i < s.size()){
            if(s[i] == '(') left ++, i++;
            else{
                if(i + 1 == s.size()){
                    if(left) ans ++, left--;
                    else ans += 2;
                    break;
                }else{
                    if(s[i + 1] == ')'){
                        if(left) left --;
                        else ans ++;
                        i += 2;
                    }else{
                        if(left) ans ++, left--;
                        else ans += 2;
                        i += 1;
                    }
                }
            }
        }
        return ans + 2 * left;
    }
};
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);
        int left = 0;
        for(int i = 0; i < n; i++){
            if(seq[i] == '('){
                ans[i] = left ++ % 2;
            }else{
                ans[i] = --left % 2;
            }
        }
        return ans;
    }
};