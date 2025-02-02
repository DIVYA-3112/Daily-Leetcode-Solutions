class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i+1] < nums[i])
            {
                ind = i+1;
                break;
            }
        }

        if(ind == -1) return true;
        for(int i=ind; i<n-1; i++)
        {
            if(nums[i+1] < nums[i])
            {
                return false;
            }
        }

        return (nums[0] >= nums[n-1]);
    }
};