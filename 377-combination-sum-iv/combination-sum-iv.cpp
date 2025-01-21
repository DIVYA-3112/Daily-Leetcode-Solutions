class Solution {
public:
 
    int fun(vector<int> &nums, int sum, int n, vector<int> &dp)
    {
        if(sum < 0) return 0;
        if(sum == 0) return 1;

        if(dp[sum] != -1) return dp[sum];

        int pick = 0;
        for(int i=0; i<n; i++)
        {
            pick += fun(nums, sum - nums[i], n, dp);
        }
        return dp[sum] = pick;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return fun(nums, target, n, dp);
    }
};