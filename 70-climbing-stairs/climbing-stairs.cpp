class Solution {
public:
    int fun(int n, vector<int> &dp)
    {
        if(n == 0) return 1;
        else if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];
        return dp[n] = fun(n-1,dp) + fun(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        // return fun(n,dp);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};