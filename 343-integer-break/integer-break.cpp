class Solution {
public:

    // int fun(int n, vector<int> &dp)
    // {
    //     if(n == 1) return 1;

    //     if(dp[n] != -1) return dp[n];

    //     int ans = 0;
    //     for(int i=1; i<=n/2; i++)
    //     {
    //         ans = max(ans, max(i * fun(n-i,dp), i * (n-i)));
    //     }
    //     return dp[n] = ans;
    // }
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        // return fun(n,dp);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            int ans = 0;
            for(int j=1; j<=i/2; j++)
            {
                ans = max({ans, j * dp[i-j], j * (i-j)});
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};