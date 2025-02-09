class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long n = nums.size();
        for(int i=0; i<n; i++)
        {
            nums[i] -= i;
            mp[nums[i]]++;
        }
        long long ans = 0;
        for(auto it : mp)
        {
            long long k = it.second;
            k = (k * (k-1))/2;
            ans += k;
        }

        ans = ((n * (n-1))/2) - ans;
        return ans;
    }
};