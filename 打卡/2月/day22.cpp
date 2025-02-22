#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        vector<pair<int, int>> cnt;
        for(int i = 0; i < n; i++){
            cnt.push_back({speed[i], efficiency[i]});
        }
        sort(cnt.begin(), cnt.end(), [&](const auto &v1, const auto &v2){return v1.second > v2.second;});
        long long s = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long min_e = cnt[i].second;
            s += cnt[i].first;
            que.push(cnt[i]);
            ans = max(ans, min_e * s);
            if(que.size() == k){
                s -= que.top().first;
                que.pop();
            }
        }
        return ans % int(1e9 + 7);
    }
};
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, less<pair<long long, int>>> que;
        unordered_map<int, long long> ump;
        vector<long long> ans;
        for(int i = 0; i < nums.size(); i++){
            ump[nums[i]] += freq[i];
            que.push({ump[nums[i]], nums[i]});
            while(ump[que.top().second] != que.top().first){
                que.pop();
            }
            ans.push_back(que.top().first);
        }
        return ans;
    }
};
// c++默认大根堆
// greater是小根堆
class StockPrice {
    public:
        StockPrice() {
            
        }
        void update(int timestamp, int price) {
            mp[timestamp] = price;
            max_que.push({price, timestamp});
            min_que.push({price, timestamp});
        }
        
        int current() {
            auto it = mp.rbegin();
            return it->second;   
        }
        
        int maximum() {
            while(mp[max_que.top().second] != max_que.top().first) max_que.pop();
            return max_que.top().first;
        }
        
        int minimum() {
            while(mp[min_que.top().second] != min_que.top().first) min_que.pop();
            return min_que.top().first;
        }
    private:
        map<int, int> mp;
        priority_queue<pair<int, int>> max_que;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_que;
    };