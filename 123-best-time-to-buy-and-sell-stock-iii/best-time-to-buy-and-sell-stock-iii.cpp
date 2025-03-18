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
        int temp =1;
        if(cnt % 2 == 0) temp = -1;

        int done = fun(arr, ind+1, cnt-1, dp) + (temp * arr[ind]);
        int notdone = fun(arr, ind+1, cnt, dp);
        int ans = max(done, notdone);
        return dp[ind][cnt] = ans;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (5, 0));
        // base cases
        dp[n-1][1] = arr[n-1];
        dp[n-1][3] = arr[n-1];

        for(int ind=n-2; ind>=0; ind--)
        {
            for(int cnt=1; cnt<5; cnt++)
            {
                int temp = 1;
                if(cnt % 2 == 0) temp = -1;

                int done = dp[ind+1][cnt-1] + (temp * arr[ind]);
                int notdone = dp[ind+1][cnt];
                dp[ind][cnt] = max(done, notdone);
            }
        }

        return dp[0][4];

        // return fun(arr, 0, 4, dp);
    }
};