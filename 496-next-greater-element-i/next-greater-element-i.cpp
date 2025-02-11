class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n = nums2.size();
        vector<int> nge(n,-1);
        for(int i=0; i<n; i++)
        {
            mp[nums2[i]] = i;
        }

        stack<int> st;
        st.push(nums2[n-1]);
        for(int i=n-2; i>=0; i--)
        {
            if(nums2[i] < st.top())
            {
                nge[i] = st.top();
            }

            while(!st.empty() && nums2[i] > st.top())
            {
                st.pop();
            }

            if(!st.empty())
            {
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++)
        {
            ans.push_back(nge[mp[nums1[i]]]);
        }
        return ans;
    }
};