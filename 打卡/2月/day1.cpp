#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end()){
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }   
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> record;
        for(auto &str : strs){
            auto c = str;
            sort(c.begin(), c.end());
            record[c].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto &[k, v] : record){
            ans.push_back(move(v));
        }
        return ans;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        for(auto &num : nums) mp[num] ++;
        int t = INT32_MIN;
        int cnt = 0;
        int ans = 0;
        for(auto &[k, _] : mp){
            if(t == INT_MIN){
                t = k;
                cnt ++;
            }else{
                if(k == t + 1){
                    t = k;
                    cnt ++;
                }
                else{
                    ans = max(ans, cnt);
                    t = k;
                    cnt = 1;
                }
            }
        }     
        return max(ans, cnt);
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int r = 0;
        while(r < nums.size()){
            if(nums[r] != 0){
                swap(nums[l], nums[r]);
                l ++;
            }
            r++;
        }     
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = (int)height.size() - 1;
        while(l < r){
            if(height[r] > height[l]){
                ans = max(ans, height[l] * (r - l));
                l++;
            }else{
                ans = max(ans, height[r] * (r - l));
                r--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            int v = height[i];
            while(!st.empty() && v > height[st.top()]){
                int l = st.top();
                st.pop();
                if(!st.empty()){
                    ans += (i - st.top() - 1) * (min(v, height[st.top()]) - height[l]);
                }
            }
            st.push(i);
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> cnt;
        int ans = 0;
        while(r < s.size()){
            int i = s[r];
            if(!cnt[i]){
                r++;
                cnt[i]++;
            }else{
                while(cnt[i]){
                    cnt[s[l]]--;
                    l++;
                }
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp1, mp2;
        for(char c : p) mp1[c] ++;
        int l = 0;
        int r = p.size() - 1;
        for(int i = 0; i <= r; i++) mp2[s[i]] ++;
        vector<int> ans;
        auto check = [&]() -> bool{
            for(auto &[k, v] : mp1){
                if(mp2[k] != v) return false;
            }
            return true;
        };
        while(r < s.size()){
            if(check()){
                ans.push_back(l);
            }  
            mp2[s[l]] --;
            l++;
            r++;
            mp2[s[r]] ++;
        }
        return ans;
    }
};