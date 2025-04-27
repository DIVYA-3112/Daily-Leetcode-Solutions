class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=1; i<n-1; i++)
        {
            int k = (nums[i-1] + nums[i+1]);
            if(2*k == nums[i]) ans++;
        }
        return ans;
    }
};