class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n,0);

        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            prefixSum[i] = sum;
        }

        int maxi = prefixSum[0];
        int mini = prefixSum[0];
        int ans = abs(prefixSum[0]);

        for(int i=1; i<n; i++)
        {
            ans = max(ans, max(maxi - prefixSum[i], prefixSum[i] - mini));
            ans = max(ans, max(abs(maxi), abs(mini)));
            maxi = max(prefixSum[i], maxi);
            mini = min(prefixSum[i], mini);
        }
        ans = max(ans, max(abs(maxi), abs(mini)));
        return ans;
    }
};