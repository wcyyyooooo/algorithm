#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g;
        g.resize(numCourses);
        vector<int> cnt(numCourses, 0);
        vector<bool> vis(numCourses, false);
        for(auto &e : prerequisites){
            int a = e[0], b = e[1];
            g[a].push_back(b);
            cnt[b] ++;
        }
        queue<int> que;
        for(int i = 0; i < numCourses; i++){
            if(!cnt[i]) que.push(i);
        }
        while(!que.empty()){
            int t = que.front();
            que.pop();
            vis[t] = true;
            for(auto nxt : g[t]){
                if(!vis[nxt]){
                    cnt[nxt]--; 
                    if(!cnt[nxt]) que.push(nxt);
                }
            }
        }
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        function<void(int, int)> dfs = [&](int n, int st){
            if(n == nums.size()){
                ans.push_back(path);
                return;
            }
            for(int i = 0; i < nums.size(); i++){
                if(!(st >> i & 1)){
                    path.push_back(nums[i]);
                    dfs(n + 1, st + (1 << i));
                    path.pop_back();
                }
            }
        };
        dfs(0, 0);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        function<void(int, int)> dfs = [&](int pre, int st){
            ans.push_back(path);
            for(int i = pre; i < nums.size(); i++){
                if(!(st >> i & 1)){
                    path.push_back(nums[i]);
                    dfs(i + 1, st + (1 << i));
                    path.pop_back();
                }
            }
        };
        dfs(0, 0);
        return ans;
    }
};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<vector<string>> hs = {{}, {}, {"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}}; 
        vector<string> ans;
        function<void(int, string)> dfs = [&](int cur, string s){
            if(cur == digits.size()){
                ans.push_back(s);
                return;
            }
            int t = digits[cur] - '0';
            for(int i = 0; i < hs[t].size(); i++){
                dfs(cur + 1, s + hs[t][i]);
            }
        };     
        dfs(0, "");
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        function<void(int, int)> dfs = [&](int x, int s){
            if(s > target) return;
            if(s == target){
                ans.push_back(path);
                return;
            } 
            for(int i = x; i < candidates.size(); i++){
                path.push_back(candidates[i]);
                dfs(i, s + candidates[i]);
                path.pop_back();
            }
        };
        sort(candidates.begin(), candidates.end());
        dfs(0, 0);
        return ans;
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, string)> dfs = [&](int l, int r, string s){
            if(l > n || r > n) return;
            if(l == r && l == n){
                ans.push_back(s);
                return;
            }
            if(l > r){
                dfs(l, r + 1, s + ")");
            }
            dfs(l + 1, r, s + "(");
        };
        dfs(0, 0, "");
        return ans;
    }
};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n);
        for(int i = 0; i < n; i++){
            vis[i].resize(m);
            for(int j = 0; j < m; j++) vis[i][j] = false;
        }
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        bool res = false;
        function<void(int, int, string)> dfs = [&](int x, int y, string s){
            if(s == word){
                res = true;
                return;
            }
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    dfs(nx, ny, s + board[nx][ny]);
                    vis[nx][ny] = false;
                }
            }
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vis[i][j] = true;
                string s = "";
                s.insert(s.begin(), board[i][j]);
                dfs(i, j, s);
                vis[i][j] = false;
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        function<void(int)> dfs = [&](int cur){
            if(cur == s.size()){
                ans.push_back(path);
                return;
            }
            for(int i = cur; i < s.size(); i++){
                string sub1 = s.substr(cur, i - cur + 1);
                string sub2 = sub1;
                reverse(sub2.begin(), sub2.end());
                if(sub1 == sub2){
                    path.push_back(sub1);
                    dfs(i + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path;
        for(int i = 0; i < n; i++){
            string s(n, '.');
            path.push_back(s);
        }
        auto check = [&](int x, int y)->bool{
            for(int i = 0; i < x; i++){
                if(path[i][y] == 'Q') return false;
            }
            for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
                if(path[i][j] == 'Q') return false;
            }
            for(int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++){
                if(path[i][j] == 'Q') return false;
            }
            return true;
        };
        function<void(int)> dfs = [&](int x){
            if(x == n){
                ans.push_back(path);
                return;
            }
            for(int i = 0; i < n; i++){
                if(check(x, i)){
                    path[x][i] = 'Q';
                    dfs(x + 1);
                    path[x][i] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(i == nums.size() || nums[i] != target) return {-1, -1};
        int j = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {i, j};
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }else{
                if(!st.size()) return false;
                if(c == ')'){
                    if(st.top() == '(') st.pop();
                    else return false;
                }
                if(c == ']'){
                    if(st.top() == '[') st.pop();
                    else return false;
                }
                if(c == '}'){
                    if(st.top() == '{') st.pop();
                    else return false;
                }
            }
        }  
        return st.size() == 0;   
    }
};
class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
        st.push({0, INT32_MAX});
    }
    
    void push(int val) {
        int mn = min(st.top().second, val);
        st.push({val, mn});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> st;
        int i = 0;
        string ans = "";
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                cnt = cnt * 10 + s[i] - '0';
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i];
            }else if(s[i] == '['){
                num.push(cnt);
                st.push(ans);
                ans = ""; cnt = 0;
            }else{
                int d = num.top();
                num.pop();
                string t = st.top();
                st.pop();
                for(int j = 0; j < d; j++){
                    t += ans;
                }
                ans = t;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        int n = temperatures.size();
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if(!st.empty()) ans[i] = st.top() - i;
            else ans[i] = 0;
            st.push(i);
        }
        return ans;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

        }
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int pre = st.top(); st.pop();
                if(st.size()){
                    ans = max(ans, (i - st.top() - 1) * heights[pre]);
                }else ans = max(ans, heights[pre] * i);
            }
            st.push(i);
        }      
        return ans;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto &num : nums) mp[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> que;
        for(auto &[k, v] : mp){
            que.push({v, k});
        }   
        vector<int> ans;   
        for(int i = 0; i < k; i++){
            ans.push_back(que.top().second);
            que.pop();
        }
        return ans;
    }
};
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> que1;
    priority_queue<int, vector<int>, greater<int>> que2;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(que1.size() != que2.size()){
            que2.push(num);
        }else que1.push(num);
    }
    
    double findMedian() {
        if(que1.size() == que2.size()){
            return ((double)que1.top() + (double)que2.top()) / 2;
        }
        return (double)que2.top();
    }
};
