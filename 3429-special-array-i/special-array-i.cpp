class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] % 2 == 0) nums[i] = 0;
            else nums[i] = 1;
        }

        for(int i=0; i<n-1; i++)
        {
            if(nums[i] + nums[i+1] != 1) return false;
        }
        return true;
    }
};