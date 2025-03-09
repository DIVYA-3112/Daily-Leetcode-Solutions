class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        unordered_map<int,vector<int>> mp;
        vector<long long> ans(n,0);
        for(int i=0; i<n; i++)
        {
            mp[nums1[i]].push_back(i);
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        vector<int> uk;
        for(auto &[key, _] : mp)
        {
            uk.push_back(key);
        }
        sort(uk.begin(), uk.end());
        int t = uk.size();
        for(int it=0; it<t; it++)
        {
            long long oldsum = sum;
            for(int i : mp[uk[it]])
            {
                ans[i] = oldsum;
                int temp = nums2[i];
                if(pq.size() == k && pq.top() < temp)
                {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(temp);
                    sum += temp;
                }
                else if(pq.size() < k)
                {
                    sum += temp;
                    pq.push(temp);
                }
            }
        }
        return ans;
    }
};