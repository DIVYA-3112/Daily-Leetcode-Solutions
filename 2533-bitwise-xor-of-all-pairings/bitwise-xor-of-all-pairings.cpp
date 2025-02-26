class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int ans = 0;
        if(n1 % 2 == 1)
        {
            for(int i=0; i<n2; i++)
            {
                ans = ans ^ nums2[i];
            }
        }

        if(n2 % 2 == 1)
        {
            for(int i=0; i<n1; i++)
            {
                ans = ans ^ nums1[i];
            }
        }

        return ans;
        
    }
};