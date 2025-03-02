class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int ind = n-1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] % 2 == 1)
            {
                ans[ind--] = 1;
            }
        }
        return ans;
    }
};