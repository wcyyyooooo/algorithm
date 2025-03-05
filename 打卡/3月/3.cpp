#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* son[26];
    vector<int> cnt;
    Node(){
        fill(begin(son), end(son), nullptr);
    }
};
class Trie{
private:
    Node *root;
public:
    Trie(){
        root = new Node;
    }
    void insert(string &s, int idx){
        Node* cur = root;
        for(auto &c : s){
            int i = c - 'a';
            if(cur->son[i] == nullptr){
                cur->son[i] = new Node;
            }
            cur = cur->son[i];
            cur->cnt.push_back(idx);
        }
    }
    Node *get_root(){
        return root;
    }
};
class WordFilter {
private:
    Trie suf;
    Trie pre;
public:
    WordFilter(vector<string>& words) {
        suf = Trie();
        pre = Trie();
        for(int i = 0; i < words.size(); i++){
            pre.insert(words[i], i);
            reverse(words[i].begin(), words[i].end());
            suf.insert(words[i], i);
        }
    }
    
    int f(string pref, string suff) {
        reverse(suff.begin(), suff.end());
        Node* cur1 = pre.get_root();
        for(auto &c : pref){
            int i = c - 'a';
            if(cur1->son[i] == nullptr) return -1;
            cur1 = cur1->son[i]; 
        }
        Node* cur2 = suf.get_root();
        for(auto &c : suff){
            int i = c - 'a';
            if(cur2->son[i] == nullptr) return -1;
            cur2 = cur2->son[i]; 
        }
        vector<int> &a = cur1->cnt;
        vector<int> &b = cur2->cnt;
        int i = (int)a.size() - 1;
        int j = (int)b.size() - 1;
        while(i >= 0 and j >= 0){
            if(a[i] == b[j]) return a[i];
            else if(a[i] > b[j]) i--;
            else j--;
        }
        return -1;
    }
};
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> cost(n + 1, vector<int>(n + 1));
        // 计算s[i:j]是否为回文串
        for(int l = 2; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){
                int j = i + l - 1;
                if(s[i] == s[j]) cost[i][j] = cost[i + 1][j - 1];
                else cost[i][j] = cost[i + 1][j - 1] + 1;
            }
        }
        // dp[i][j]表示把s[0:i]分为j段的最小变换次数，如果dp[i][j] == 0表示可以把s[0:i]分为j个回文串
        vector<vector<int>> dp(n + 1, vector<int>(3));
        for(int i = 0; i < n; i++){
            dp[i][0] = cost[0][i];
            for(int k = 1; k < 3; k++) dp[i][k] = INT32_MAX;
        }
        for(int k = 1; k < 3; k++){
            for(int i = k; i < n; i++){
                for(int j = i; j < n; j++){
                    dp[j][k] = min(dp[j][k], dp[i - 1][k - 1] + cost[i][j]);
                }
            }
        }
        return dp[n - 1][2] == 0;
    }
};
class dsu{
private:
    vector<int> p;
public:
    dsu(int n){
        p.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py) p[py] = px;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        dsu d(27);
        vector<string> unequals;
        for(auto &s : equations){
            int a = s[0] - 'a';
            int b = s[3] - 'a';
            if(s[1] == '=') d.unite(a, b);
            else unequals.push_back(s);
        }
        for(auto &s : unequals){
            int pa = d.find(s[0] - 'a');
            int pb = d.find(s[3] - 'a');
            if(pa == pb) return false; 
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> ump;
        dsu d(accounts.size() + 1);
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(ump.contains(accounts[i][j])) d.unite(i, ump[accounts[i][j]]);
                else ump[accounts[i][j]] = i;
            }
        }
        unordered_map<int, set<string>> cnt;
        for(int i = 0; i < accounts.size(); i++){
            int pi = d.find(i);
            for(int j = 1; j < accounts[i].size(); j++) cnt[pi].insert(accounts[i][j]);
        }
        vector<vector<string>> ans;
        for(auto &[k, s] : cnt){
            vector<string> ai{accounts[k][0]};
            for(auto si : s){
                ai.push_back(move(si));
            }
            ans.push_back(move(ai));
        }
        return ans;
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        dsu d(s.size() + 1);
        for(auto &pair : pairs){
            d.unite(pair[0], pair[1]);
        }      
        unordered_map<int, vector<int>> cnt;
        for(int i = 0; i < s.size(); i++){
            cnt[d.find(i)].push_back(i);
        }
        string ans;
        ans.resize(s.size());
        for(auto &[k, v] : cnt){
            vector<char> c;
            for(auto &vi : v) c.push_back(s[vi]);
            ranges::sort(c);
            for(int i = 0; i < v.size(); i++) ans[v[i]] = c[i];
        }
        return ans;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        dsu d(26);
        for(int i = 0; i < s1.size(); i++){
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            d.unite(a, b);
        }
        unordered_map<int, int> ump;
        for(int i = 0; i < 26; i++){
            int root = d.find(i);
            if(ump.contains(root)) ump[root] = min(ump[root], i);
            else ump[root] = i; 
        };
        string ans;
        for(auto &c : baseStr){
            int i = d.find(c - 'a');
            ans.push_back(ump[i] + 'a');
        }
        return ans;
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        dsu d(source.size());
        for(auto &allow : allowedSwaps){
            d.unite(allow[0], allow[1]);
        }
        unordered_map<int, vector<int>> cnt;
        for(int i = 0; i < source.size(); i++){
            int root = d.find(i);
            cnt[root].push_back(i);
        }
        int ans = 0;
        for(auto &[_, v] : cnt){
            unordered_map<int, int> used;
            for(auto &vi : v) used[source[vi]] += 1;
            int x = 0;
            for(auto &vi : v){
                if(used[target[vi]]){
                    x += 1;
                    used[target[vi]] -= 1;
                }
            }
            ans += v.size() - x;
        }
        return ans;
    }
};