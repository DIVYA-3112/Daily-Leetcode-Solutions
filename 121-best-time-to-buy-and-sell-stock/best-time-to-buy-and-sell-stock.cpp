class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 1e9;
        int ans = 0;
        for(int num : prices)
        {
            mini = min(mini, num);
            ans = max(ans, num - mini);
        }
        return ans;
    }
};