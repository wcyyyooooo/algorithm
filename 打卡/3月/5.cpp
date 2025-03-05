#include <bits/stdc++.h>
using namespace std;
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
    int cal(){
        int ans = 0;
        for(int i = 0; i < p.size(); i++){
            if(p[i] == i) ans += 1;
        }
        return ans;
    }
};
class hash_t{
private:
    unordered_map<int, int> ump;
    int x;
public:
    hash_t(vector<vector<int>> &v){
        for(auto &vi : v){
            ump[vi[0]] = x++;
            ump[vi[0] + 10001] = x++;
        }
    }
    int get(int v){
        return ump[v];
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        dsu d(2 * stones.size());
        hash_t h(stones);
        for(auto &stone : stones){
            d.unite(h.get(stone[0]), h.get(stone[1] + 10001));
        }
        return stones.size() - d.cal();
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        auto check = [&](string &s1, string &s2){
            int x = 0;
            for(int i = 0; i < s1.size(); i++){
                if(s1[i] != s2[i]) x++;
                if(x > 2) return false;
            }
            return true;
        };
        dsu d(strs.size());
        for(int i = 0; i < strs.size(); i++){
            for(int j = i + 1; j < strs.size(); j++){
                if(check(strs[i], strs[j])) d.unite(i, j);
            }
        }
        return d.cal();
    }
};
// 贪心，如果遍历前半部分，前半部分如果有非a的字母就把其改成a，否则就把最后一个字母改成b（全是a)改成(aaaaab)
class Solution {
    public:
        string breakPalindrome(string palindrome) {
            if(palindrome.size() == 1) return "";
            for(int i = 0; i < palindrome.size() / 2; i++){
                if(palindrome[i] != 'a'){
                    return palindrome.substr(0, i) + "a" + palindrome.substr(i + 1, (int)palindrome.size() - i);
                }
            }
            return palindrome.substr(0, (int)palindrome.size() - 1) + "b";
        }
    };