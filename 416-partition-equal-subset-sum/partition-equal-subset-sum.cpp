class Solution {
public:

    bool fun(vector<int> nums, int ind, int sum,vector<vector<int>> &dp)
    {
        // base case
        if(ind == 0) return (sum == nums[0]);
        if(sum == 0) return true;

        // dp check
        if(dp[ind][sum] != -1) return dp[ind][sum];

        // recursion
        bool nt = fun(nums,ind - 1,sum,dp);
        bool t = false;
        if(nums[ind] <= sum) t = fun(nums,ind-1,sum-nums[ind],dp);

        return dp[ind][sum] = (nt || t);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 != 0) return false;
        sum /= 2;
        // vector<vector<int>> dp(n,vector<int>(sum+1,0));
        vector<int> prev(sum+1,0);
        prev[0] = 1;
        vector<int> temp(sum+1,0);
        temp[0] = 1;
        // return fun(nums,n-1,sum,dp);
        // tabulation - base case
        if(nums[0] <= sum) prev[nums[0]] = 1;
        // for(int i = 0; i < n; i++) dp[i][0] = 1;

        for(int i = 1; i < n; i++)
        {
            for(int tar = 1; tar <= sum; tar++)
            {
                bool t = false;
                if(tar >= nums[i]) t = prev[tar-nums[i]];
                bool nt = prev[tar];
                temp[tar] = (t || nt);
            }

            prev = temp;
            temp[0] = 1;
        }

        return prev[sum];
    }
};