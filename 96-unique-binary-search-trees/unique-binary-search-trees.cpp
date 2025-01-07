class Solution {
public:
    int fun(int l, int r, vector<int> &dp)
    {
        if(l >= r) return 1;

        int ans = 0;
        if(dp[r-l+1] != -1) return dp[r-l+1];
        for(int i=l; i<=r; i++)
        {
            ans += (fun(l,i-1,dp) * fun(i+1,r,dp));
        }
        return dp[r-l+1] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        int ans = 0;
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int left = j;
                int right = i-j-1;

                dp[i] += (dp[left] * dp[right]);
            }
        }
        return dp[n];
    }
};