#define pii pair<int,int>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pii> pq;
        int n = nums.size();

        for(int i=0; i<k-1; i++)
        {
            pq.push({nums[i], i});
        }

        for(int i=k-1; i<n; i++)
        {
            while(!pq.empty() && i - pq.top().second >= k)
            {
                pq.pop();
            }
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);


        }
        return ans;
    }
};