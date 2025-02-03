class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxinc = 0;
        int maxdec = 0;
        int n = nums.size();
        int li = 0, ld = 0;
        for(int i=1; i<n; i++)
        {
            if(nums[i] <= nums[i-1])
            {
                maxinc = max(maxinc, i-li);
                li = i;
            }

            if(nums[i] >= nums[i-1])
            {
                maxdec = max(maxdec, i-ld);
                ld = i;
            }
        }

        maxinc = max(maxinc, n - li);
        maxdec = max(maxdec, n - ld);

        return max(maxinc,maxdec);
    }
};