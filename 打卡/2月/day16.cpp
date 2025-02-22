#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> cnt(102);
        for(auto &v : nums){
            cnt[v[0]] ++;
            cnt[v[1] + 1] --;
        }
        for(int i = 1;i <= 100; i++){
            cnt[i] += cnt[i - 1];
        }
        int ans = 0;
        for(int i = 1; i <= 100; i++){
            if(cnt[i]) ans += 1;
        }
        return ans;
    }
};
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> cnt(52);
        for(auto &v : ranges){
            cnt[v[0]] ++;
            cnt[v[1] + 1] --;
        }
        for(int i = 1; i <= right; i++) cnt[i] += cnt[i - 1];
        for(int i = left; i <= right; i++) if(!cnt[i]) {return false;}
        return true;
    }
};
class Solution {
    public:
        int maximumPopulation(vector<vector<int>>& logs) {
            vector<int> cnt(102);
            for(auto &log : logs){
                cnt[log[0] - 1949] ++;
                cnt[log[1] - 1949] --;
            }
            for(int i = 1; i <= 100; i++) cnt[i] += cnt[i - 1];
            int ans = 0;
            for(int i = 1; i <= 100; i++){
                if(cnt[i] > cnt[ans]) ans = i;
            }
            return ans + 1949;
        }
};
class Solution {
    public:
        bool carPooling(vector<vector<int>>& trips, int capacity) {
            vector<int> cnt(1002);
            for(auto &trip : trips){
                cnt[trip[1] + 1] += trip[0];
                cnt[trip[2] + 1] -= trip[0];
            }
            for(int i = 1; i <= 1001; i++) cnt[i] += cnt[i - 1];
            for(int i = 1; i <= 1001; i++){
                if(cnt[i] > capacity) return false;
            }
            return true;
        }
};
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> cnt(n + 2);
        for(auto &book : bookings){
            cnt[book[0]] += book[2];
            cnt[book[1] + 1] -= book[2];
        }
        for(int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
        return vector<int>(cnt.begin() + 1, cnt.begin() + n + 1);
    }
};
class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            vector<int> cnt(n + 2);
            nums.insert(nums.begin(), 0);
            for(int i = 1; i <= n; i++){
                cnt[i] = nums[i] - nums[i - 1];
            }
            for(auto &query : queries){
                cnt[query[0] + 1] -= 1;
                cnt[query[1] + 2] += 1;
            }
            for(int i = 1; i <= n; i++){
                cnt[i] += cnt[i - 1];
                if(cnt[i] > 0) return false;
            }
            return true;
        }
};
class Solution {
    public:
        string shiftingLetters(string s, vector<vector<int>>& shifts) {
            int n = s.size();
            vector<int> a(n + 2), b(n + 2);
            for(int i = 1; i <= n; i++) a[i] = (s[i - 1] - 'a');
            for(int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
            for(auto &shift : shifts){
                int v = shift[2] == 1 ? 1 : -1;
                b[shift[0] + 1] += v;
                b[shift[1] + 2] -= v;
            }
            for(int i = 1; i <= n; i++) b[i] += b[i - 1];
            string ans = "";
            for(int i = 1; i <= n; i++){
                ans += ('a' + (b[i] % 26 + 26) % 26);
            }
            return ans;
        }
    };
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> a(n + 2);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            a[i] += a[i - 1];
            if((a[i] + nums[i - 1]) % 2 == 0){
                if(i + k - 1 > n) return -1;
                ans ++;
                a[i] += 1;
                a[i + k] -= 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> cnt(n + 2);
        for(auto &request : requests){
            cnt[request[0] + 1] += 1;
            cnt[request[1] + 2] -= 1;
        }
        for(int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
        ranges::sort(nums);
        sort(cnt.begin() + 1, cnt.begin() + n + 1);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans = (ans + (long long)cnt[i + 1] * (long long)nums[i]) % int(1e9 + 7);
        }
        return ans;
    }
};
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        vector<int> cnt(n + 1);
        cnt[1] = target[0];
        for(int i = 2; i <= n; i++){
            cnt[i] = target[i - 1] - target[i - 2];
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++) if(cnt[i] >= 0) ans += cnt[i];
        return ans;
    }
};
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        auto check = [&](int k) -> bool{
            vector<int> cnt(n + 2);
            for(int i = 1; i <= n; i++){
                cnt[i] = nums[i] - nums[i - 1];
            }
            for(int i = 0; i < k; i++){
                cnt[queries[i][0] + 1] -= queries[i][2];
                cnt[queries[i][1] + 2] += queries[i][2];
            } 
            for(int i = 1; i <= n; i++){
                cnt[i] += cnt[i - 1];
                if(cnt[i] > 0) return false;
            }
            return true;
        };
        int l = 1, r = queries.size();
        while(l < r){
            int mid = (l + r) / 2;
            if(check(mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return check(l) ? l : -1;
    }
};
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> cnt;
        for(auto &seg : segments){
            cnt[seg[0]] += seg[2];
            cnt[seg[1]] += seg[2];
        }
        vector<vector<long long>> ans;
        long long s = 0;
        int last = 0;
        for(auto &[k, v] : cnt){
            if(s) ans.push_back({last, k, s});
            last = k;
            s += v;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> cnt;
        for(auto &flower : flowers){
            cnt[flower[0]] += 1;
            cnt[flower[1] + 1] -= 1;
        }      
        int s = 0;
        vector<int> ans(people.size());
        vector<pair<int, int>> rec;
        for(int i = 0; i < people.size(); i++) rec.push_back({people[i], i});
        ranges::sort(rec);
        auto it = cnt.begin();
        for(auto &p : rec){
            while(it != cnt.end() && it->first <= p.first){
                s += it->second;
                it++;
            }
            ans[p.second] = s;
        }
        return ans;
    }
};
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) target[i] -= nums[i];
        vector<int> diff(n + 1);
        diff[1] = target[0];
        for(int i = 2; i <= n; i++) diff[i] = target[i - 1] - target[i - 2]; 
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(diff[i] > 0) ans += diff[i];
        }
        return ans;
    }
};