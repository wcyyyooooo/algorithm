#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int s = 0;
        int ans = 0;
        cnt[0] = 1;
        for(auto num : nums){
            s += num;
            ans += cnt[s - k];
            cnt[s] ++;
        }      
        return ans;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            while(!que.empty() && nums[que.back()] <= nums[i]) que.pop_back();
            que.push_back(i);
            if(i - k >= 0 && que.front() == i - k) que.pop_front();
            if(i - k + 1 >= 0) ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char, int> mp1, mp2;
        for(char c : t) mp1[c] ++;
        int l = 0;
        int r = 0;
        auto check = [&]() -> bool {
            for(auto &[k, v] : mp1){
                if(mp2[k] < v) return false;
            }
            return true;
        };
        int ansl = -1;
        int ansr = s.size();
        for(int r = 0; r < s.size(); r++){
            mp2[s[r]] ++;
            while(check()){
                if(r - l < ansr - ansl){
                    ansl = l;
                    ansr = r;
                }
                mp2[s[l]]--;
                l++;
            }
        }
        return ansl != -1 ? s.substr(ansl, ansr - ansl + 1) : "";
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            pre = max(pre + nums[i], nums[i]);
            ans = max(ans, pre);
        }      
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto v1, auto v2){return v1[0] < v2[0];});
        int l = 0;
        vector<vector<int>> ans;
        int last = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > last){
                ans.push_back({intervals[l][0], last});
                l = i;
                last = intervals[i][1];
            }else{
                last = max(last, intervals[i][1]);
            }
        }
        ans.push_back({intervals[l][0], last});
        return ans;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        k = nums.size() - k;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<int> pre(nums.size(), 1);
        vector<int> post(nums.size(), 1);
        vector<int> ans;
        for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] * nums[i];
        for(int i = n; i >= 1; i--) post[i] = post[i + 1] * nums[i];
        for(int i = 1; i <= n; i++){
            ans.push_back(pre[i - 1] * post[i + 1]);
        }
        return ans;
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> mp1, mp2;
        int n = matrix.size(); int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!matrix[i][j]){
                    mp1[i] = true;
                    mp2[j] = true;
                }
            }
        }
        for(auto &[k, _] : mp1){
            for(int i = 0; i < m; i++) matrix[k][i] = 0;
        }
        for(auto &[k, _] : mp2){
            for(int i = 0; i < n; i++) matrix[i][k] = 0;
        }
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int d = 0;
        int i = 0, j = 0;
        for(int k = 0; k < n * m; k++){
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT32_MAX;
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            if(x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] == INT32_MAX){
                d = (d + 1) % 4;
            }
            i += dir[d][0];
            j += dir[d][1];
        }
        return ans;
    }
};
// i j -> j n - i - 1
// i j -> n - i - 1 j 
// i j -> j n - i - 1
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < m; j++) swap(matrix[i][j], matrix[n - i - 1][j]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++) swap(matrix[i][j], matrix[j][i]);
        }
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m - 1;
        while(i < n && j >= 0){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] > target){
                j--;
            }else i++;
        }
        return false;
    }
};
class Node{
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int k = 0, int v = 0) : key(k), value(v){}
};
class LRUCache {
private:
    int capacity;
    Node *head;
    unordered_map<int, Node*> key_to_node;
    void remove(Node *x){
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    void push_front(Node *x){
        x->next = head->next;
        x->prev = head;
        head->next = x;
        x->next->prev = x;
    }
    Node *get_node(int key){
        auto it = key_to_node.find(key);
        if(it == key_to_node.end()) return nullptr;
        Node *node = it->second;
        remove(node);
        push_front(node);
        return node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node();
        head->next = head;
        head->prev = head;
    }
    
    int get(int key) {
        auto node = get_node(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        auto node = get_node(key);
        if(node == nullptr){
            auto nwnode = new Node(key, value);
            key_to_node[key] = nwnode;
            push_front(nwnode);
        }else{
            node->value = value;
            return;
        }
        if(key_to_node.size() > capacity){
            auto back_node = head->prev;
            remove(back_node);
            key_to_node.erase(back_node->key);
            delete back_node;
        }
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if(nums[0] > 0 || nums.size() < 3) return ans;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l + 1] == nums[l]) l++;
                    while(l < r && nums[r - 1] == nums[r]) r--;
                    l++, r--;
                }else{
                    if(nums[i] + nums[l] + nums[r] > 0){
                        r--;
                    }else l++;
                }
            }
        }
        return ans;
    }
};
class Node{
public:
    int x;
    int y;
    int w;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Node> que;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> used(n);
        for(int i = 0; i < n; i++){
            used[i].resize(m);
            for(int j = 0; j < m; j++){
                used[i][j] = false;
                if(grid[i][j] == 2){
                    que.push({i, j, 0});
                }
            }
        }
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int ans = 0;
        while(que.size()){
            auto t = que.front();
            que.pop();
            int x = t.x;
            int y = t.y;
            ans = max(ans, t.w);
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !used[nx][ny]){
                    grid[nx][ny] = 2;
                    used[nx][ny] = true;
                    que.push({nx, ny, t.w + 1});
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};
