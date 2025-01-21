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
    const int MOD = INT_MAX;
    vector<long long> dp(target + 1, 0);
    dp[0] = 1; // Base case: 1 way to make target 0
    for (int sum = 1; sum <= target; sum++) {
        long long pick = 0;
        for (int j = 0; j < n; j++) {
            if (sum - nums[j] >= 0) {
                pick = (pick + dp[sum - nums[j]]) % MOD;
            }
        }
        dp[sum] = pick;
    }
    return dp[target];
}

};