
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, pair<int, int>>> vec(n);
        
        for (int i = 0; i < n; i++) {
            vec[i] = {nums1[i], {i, nums2[i]}};
        }
        
        sort(vec.begin(), vec.end());
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long currSum = 0;
        vector<long long> ans(n);
        
        for (int i = 0; i < n; i++) {
            int currNum = vec[i].first;
            int j = i;
            
            while (j < n && vec[j].first == currNum) {
                ans[vec[j].second.first] = currSum;
                j++;
            }
            
            for (int l = i; l < j; l++) {
                pq.push(vec[l].second.second);
                currSum += vec[l].second.second;
                
                if (pq.size() > k) {
                    currSum -= pq.top();
                    pq.pop();
                }
            }
            
            i = j - 1;
        }
        
        return ans;
    }
};