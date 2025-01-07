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
        vector<int> dp(n+1,-1);
        return fun(1,n,dp);

    }
};