#define pii pair<int,int>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // pq.push({nums1[0] + nums2[0], 0});

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = min(n1,n2);
        for(int i=0; i<n2; i++)
        {
            pq.push({nums1[0] + nums2[i], 0});
        }

        vector<vector<int>> ans;
        while(!pq.empty() && ans.size() < k)
        {
            auto fn = pq.top();
            int sum = fn.first;
            int ind = fn.second;
            ans.push_back({nums1[ind],sum-nums1[ind]});
            pq.pop();

            if(ind + 1 < n1)pq.push({nums1[ind+1] + sum - nums1[ind], ind+1});
        }

        return ans;
    }
};