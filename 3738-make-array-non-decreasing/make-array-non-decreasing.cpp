class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(nums[0]);
        int i=0;
        while(i<n)
        {
            if(nums[i] >= st.top())
            {
                st.push(nums[i]);
            }
            i++;
        }
        return st.size()-1;
    }
};