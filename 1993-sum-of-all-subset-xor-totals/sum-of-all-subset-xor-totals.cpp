class Solution {
public:

    int fun(vector<int> nums, int ind, int temp)
    {
        // base case
        if(ind >= nums.size()) return temp;

        // conditions 
        int pick = (fun(nums, ind+1, (temp ^ nums[ind])));
        int np = (fun(nums, ind+1, temp));

        return pick+np;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return fun(nums,0,0);
    }
};