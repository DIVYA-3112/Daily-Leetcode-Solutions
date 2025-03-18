class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,r=0;
        int n = nums.size();
        int mask = 0;
        int ans = 0;

        while(r < n)
        {
            while((mask & nums[r]) != 0)
            {
                mask = (mask ^ nums[l]);
                l++;
            }

            mask = (mask ^ nums[r]);
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};