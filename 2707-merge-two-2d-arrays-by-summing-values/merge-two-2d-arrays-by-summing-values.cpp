class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        // nums1.push_back({1001, 1001});
        // nums2.push_back({1001, 1001});
        int ind1 = 0, ind2 = 0;
        // int k = n1 + n2;
        vector<vector<int>> ans;

        while(ind1 < n1 && ind2 < n2)
        {
            int id1 = nums1[ind1][0];
            int id2 = nums2[ind2][0];
            int val1 = nums1[ind1][1];
            int val2 = nums2[ind2][1];

            if(id1 == id2)
            {
                ans.push_back({id1, val1 + val2});
                ind1++;
                ind2++;
            }
            else if(id1 < id2)
            {
                ans.push_back({id1, val1});
                ind1++;
            }
            else
            {
                ans.push_back({id2, val2});
                ind2++;
            }
        }

        while(ind1 < n1)
        {
            ans.push_back(nums1[ind1]);
            ind1++;
        }

        while(ind2 < n2)
        {
            ans.push_back(nums2[ind2]);
            ind2++;
        }
        
        return ans;
    }
};