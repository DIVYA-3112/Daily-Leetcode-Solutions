class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    long long temp = (nums[i]-nums[j]);
                    temp = temp * nums[k];
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};