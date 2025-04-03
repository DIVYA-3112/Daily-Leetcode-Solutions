class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n-1, 0);
        vector<int> arr(n,0);

        arr[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            arr[i] = max(arr[i+1], nums[i]);
        }


        int maxdiff = 0;
        long long ans = 0;
        for(int i=0; i<n-2; i++)
        {
            maxdiff += (nums[i] - nums[i+1]);
            maxdiff = max(0, maxdiff);

            long long temp = maxdiff * (long long)arr[i+2];
            ans = max(ans, temp);
        }
        return ans;
    }
};