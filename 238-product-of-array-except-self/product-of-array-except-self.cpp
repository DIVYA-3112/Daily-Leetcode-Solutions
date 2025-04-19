class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // vector<int> left(n,0), right(n,0);
        vector<int> ans(n,1);
        int k = 1;
        for(int i=0; i<n; i++)
        {
            ans[i] *= k;
            k *= nums[i];
        }

        k = 1;
        for(int i=n-1; i>=0; i--)
        {
            ans[i] *= k;
            k *= nums[i];
        }

        // for(int i=0; i<n; i++)
        // {
        //     int temp = 1;
        //     if(i > 0) temp *= left[i-1];
        //     if(i < n-1) temp *= right[i+1];
        //     ans[i] = temp;
        // }
        return ans;
    }
};