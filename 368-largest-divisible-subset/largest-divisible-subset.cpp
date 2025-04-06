class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> temp(n,0);
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++)
        {
            temp[i] = i;
            int maxi = 0;
            int ind = -1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    maxi = max(maxi, dp[j]);
                    if(maxi == dp[j]) ind = j;
                }
            }
            dp[i] += maxi;
            if(ind != -1) temp[i] = ind;
        }
        int ind = -1;
        int maxi = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                ind = i;
            }
        }
        
        vector<int> ans;
        int i = ind;
        while(temp[i] != i)
        {
            ans.push_back(nums[i]);
            i = temp[i];
        }
        ans.push_back(nums[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};