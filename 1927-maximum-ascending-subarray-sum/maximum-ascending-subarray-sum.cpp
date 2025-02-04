class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int last = -1;
        int ans = 0;
        for(int i : nums)
        {
            if(i > last)
            {
                sum += i;
            }
            else
            {
                ans = max(ans,sum);
                sum = i;
            }
            last = i;
        }
        ans = max(ans,sum);
        return ans;
    }
};