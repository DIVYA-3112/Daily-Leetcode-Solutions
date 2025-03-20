class Solution {
public:

    int fun(vector<int> &arr, int ind, int buy, int fee, vector<vector<int>> &dp)
    {
        // base case
        int n = arr.size();
        if(ind == n-1)
        {
            if(buy) return 0;
            else return arr[ind] - fee;
        }

        // dp check
        if(dp[ind][buy] != -1) return dp[ind][buy];

        // conditions
        int ans;
        if(buy)
        {
            int buyd = fun(arr, ind+1, 0, fee, dp) - arr[ind];
            int buynd = fun(arr, ind+1, 1, fee, dp);
            ans = max(buyd, buynd);
        }
        else if(!buy)
        {
            int selld = fun(arr, ind+1, 1, fee, dp) + arr[ind] - fee;
            int sellnd = fun(arr, ind+1, 0, fee, dp);
            ans = max(selld, sellnd);
        }
        // return ans;
        return dp[ind][buy] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return fun(prices, 0, 1, fee, dp);
    }
};