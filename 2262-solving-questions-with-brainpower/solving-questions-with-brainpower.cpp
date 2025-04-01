class Solution {
public:

    long long fun(vector<vector<int>> &que, int ind, vector<long long> &dp)
    {
        int n = que.size();
        // base case
        if(ind >= n) return 0;

        // recurson check
        if(dp[ind] != -1) return dp[ind];

        // conditions
        long long pick = fun(que, ind+1+que[ind][1], dp) + que[ind][0];
        long long np = fun(que, ind+1, dp);

        return dp[ind] = max(pick, np);
    }
    long long mostPoints(vector<vector<int>>& que) {
        int n = que.size();
        vector<long long> dp(n+1,0);
        dp[n] = 0;

        for(int i=n-1; i>=0; i--)
        {
            int k = min(n, i+1+que[i][1]);
            long long pick = dp[k] + que[i][0];
            long long np = dp[i+1];
            dp[i] = max(pick, np);
        }
        return dp[0];
    }
};