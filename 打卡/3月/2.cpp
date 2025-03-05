#include <bits/stdc++.h>
using namespace std;
struct Node{
    bool isEnd;
    Node* son[26];
    Node(){
        isEnd = false;
        fill(begin(son), end(son), nullptr);
    }
};
class Trie{
private:
    Node* root;
public:
    void insert(string s){
        Node* cur = root;
        for(auto &c : s){
            int i = c - 'a';
            if(cur->son[i] == nullptr){
                cur->son[i] = new Node;
            }
            cur = cur->son[i];
        }
        cur->isEnd = true;
    }
    bool dfs(string &s, Node *node, int pos, bool modified){
        if(s.size() == pos){
            return modified and node->isEnd;
        }
        int i = s[pos] - 'a';
        if(node->son[i]){
            if(dfs(s, node->son[i], pos + 1, modified)) return true;
        }
        if(!modified){
            for(int j = 0; j < 26; j++){
                if(i != j and node->son[j]){
                    if(dfs(s, node->son[j], pos + 1, true)) return true;
                }
            }
        }
        return false;
    }
    Node *getRoot(){
        return root;
    }
};
class MagicDictionary {
private:
    Trie* tr;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &s : dictionary) tr->insert(s);
    }
    
    bool search(string searchWord) {
        return tr->dfs(searchWord, tr->getRoot(), 0, false);
    }
};
struct TrieNode{
    TrieNode* son[26];
    int i;
    int min_l;
    TrieNode(){
        i = 0;
        min_l = INT32_MAX;
        fill(begin(son), end(son), nullptr);
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode *root = new TrieNode();
        for(int i = 0; i < wordsContainer.size(); i++){
            string s = wordsContainer[i];
            int l = s.size();
            TrieNode* cur = root;
            if(l < cur->min_l){
                cur->min_l = l;
                cur->i = i;
            }
            for(int j = l - 1; j >= 0; j--){
                int idx = s[j] - 'a';
                if(cur->son[idx] == nullptr){
                    cur->son[idx] = new TrieNode;
                }
                cur = cur->son[idx];
                if(l < cur->min_l){
                    cur->min_l = l;
                    cur->i = i;
                }
            }
        }
        vector<int> ans;
        for(auto &s : wordsQuery){
            TrieNode* cur = root;
            for(int j = (int)s.size() - 1; j >= 0; j--){
                int idx = s[j] - 'a';
                if(cur->son[idx] == nullptr){
                    break;
                }
                cur = cur->son[idx];
            }
            ans.push_back(cur->i);
        }
        return ans;
    }
};
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n + 1, vector<int>(n + 1));
        // cost[i][j]表示s[i:j]需要变换cost[i][j]次才能变成回文串
        for(int l = 2; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){
                int j = i + l - 1;
                if(s[i] == s[j]) cost[i][j] = cost[i + 1][j - 1];
                else cost[i][j] = cost[i + 1][j - 1] + 1;
            }
        }
        // dp[i][j]表示把s[0:i]分割为j个子串最小的修改次数
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++) dp[i][j] = INT32_MAX;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= min(k, i); j++){
                if(j == 1) dp[i][j] = cost[0][i - 1];
                else{
                    for(int l = j - 1; l < i; l++){
                        dp[i][j] = min(dp[i][j], dp[l][j - 1] + cost[l][i - 1]);
                    }
                }
            }
        }
        return dp[n][k];
    }
};
