#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rolling_hash(vector<int>& nums, int window_size, int base = 26, int mod = 1000000007) {
        int n = nums.size();
        vector<int> power(n + 1, 1);
        vector<int> hash_values(n - window_size + 1);

        for (int i = 1; i <= n; i++) {
            power[i] = (1LL*power[i - 1] * base) % mod;
        }

        long long current_hash = 0;
        for (int i = 0; i < window_size; i++) {
            current_hash = (1LL*current_hash * base + nums[i]) % mod;
        }
        hash_values[0] = current_hash;

        for (int i = 1; i <= n - window_size; i++) {
            current_hash = (current_hash - (1LL*power[window_size - 1] * nums[i - 1]) % mod+mod)%mod;
            current_hash = (current_hash * base + nums[i + window_size - 1]) % mod;
            hash_values[i] = current_hash;
        }
        return hash_values;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        // map<vector<int>, int> freq;
        
        int len;
        int n = nums.size();
        int l = 1;
        int h = n;
        int mid = l+(h-l)/2;
        while (l <= h) {
            unordered_map<int, int> freq;
            vector<int> hash_values = rolling_hash(nums, mid);
            bool found = false;
            for(int i:hash_values){
                freq[i]++;
            }
            for (auto it : freq) {
                if (it.second == 1) {
                    len = mid;
                    h = mid-1;
                    found = true;
                }
            }
            if(!found){
                l = mid+1;
            }
            mid = l+(h-l)/2;
        }
        return len;
    }
};