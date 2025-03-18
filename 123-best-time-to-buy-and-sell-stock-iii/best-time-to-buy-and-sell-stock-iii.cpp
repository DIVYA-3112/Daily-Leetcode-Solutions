class Solution {
public:
    int fun(vector<int> &arr, int ind, int buy, int cnt, vector<vector<vector<int>>> &dp)
    {
        // base case
        int n = arr.size();
        if(cnt == 0 && buy)
        {
            return 0;
        }
        if(ind == n-1)
        {
            if(buy==0) return arr[ind];
            else return 0;
        }

        // dp check
        if(dp[ind][buy][cnt] != -1) return dp[ind][buy][cnt];

        // conditions;
        int ans;
        if(buy)
        {
            int buyd = fun(arr, ind+1, 0, cnt, dp) - arr[ind];
            int buynd = fun(arr, ind+1, 1, cnt, dp);
            ans = max(buyd, buynd);
        }
        else
        {
            int selld = fun(arr, ind+1, 1, cnt-1, dp) + arr[ind];
            int sellnd = fun(arr, ind+1, 0, cnt, dp);
            ans = max(selld, sellnd);
        }
        return dp[ind][buy][cnt] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return fun(prices, 0, 1, 2, dp);
    }
};