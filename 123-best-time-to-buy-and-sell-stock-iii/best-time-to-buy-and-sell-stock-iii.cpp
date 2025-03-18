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
            return (cnt % 2 == 0) ? 0 : arr[ind]; 
        }

        // dp check
        if(dp[ind][cnt] != -1) return dp[ind][cnt];

        // conditions;
        int ans;
        if(cnt%2 == 0)
        {
            int buyd = fun(arr, ind+1, cnt-1, dp) - arr[ind];
            int buynd = fun(arr, ind+1, cnt, dp);
            ans = max(buyd, buynd);
        }
        else
        {
            int selld = fun(arr, ind+1, cnt-1, dp) + arr[ind];
            int sellnd = fun(arr, ind+1, cnt, dp);
            ans = max(selld, sellnd);
        }
        return dp[ind][cnt] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (5, -1));
        return fun(prices, 0, 4, dp);
    }
};