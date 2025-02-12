class Solution {
public:

    int countDigit(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += (n % 10);
            n /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            mp[countDigit(nums[i])].push_back(nums[i]);
        }

        int ans = -1;
        for(auto it : mp)
        {
            if(it.second.size() >= 2)
            {
                sort(it.second.begin(), it.second.end());
                int m = it.second.size();
                ans = max(ans, it.second[m-1] + it.second[m-2]);
            }
        }
        return ans;
    }
};