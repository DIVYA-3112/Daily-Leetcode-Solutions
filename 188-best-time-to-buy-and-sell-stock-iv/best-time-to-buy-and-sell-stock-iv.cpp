class Solution {
public:

    int fun(vector<int> &arr, int ind, int cnt, vector<vector<int>> &dp)
    {
        // base case
        int n = arr.size();
        if(cnt == 0)
        {
            return 0;
        }
        if(ind == n-1)
        {
            if(cnt % 2 == 1)
            {
                return arr[ind];
            }
            else return 0;
        }

        // dp check
        if(dp[ind][cnt] != -1) return dp[ind][cnt];

        // conditions;
        int temp = 1;
        if(cnt % 2 == 0) temp = -1;

        int done = fun(arr, ind+1, cnt-1, dp) + (temp * arr[ind]);
        int ndone = fun(arr, ind+1, cnt, dp);

        return dp[ind][cnt] = max(done, ndone);
    }
    int maxProfit(int k, vector<int>& prices) {
        k = 2*k;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return fun(prices, 0, k, dp);
    }
};