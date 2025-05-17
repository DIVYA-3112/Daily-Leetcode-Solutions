class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0,cnt1=0;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0) cnt0++;
            else if(nums[i] == 1) cnt1++;
        }

        for(int i=0; i<n; i++)
        {
            if(cnt0)
            {
                nums[i] = 0;
                cnt0--;
            }
            else if(cnt1)
            {
                nums[i] = 1;
                cnt1--;
            }
            else nums[i] = 2;
        }
        return;
    }
};