class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            pq.push(nums[i]);
        }

        cout << pq.top() << endl;

        int ans = 0;
        while(pq.size() > 1)
        {
            long long s1 = pq.top();
            pq.pop();
            if(s1 >= k) break;
            long long s2 = pq.top();
            pq.pop();
            pq.push(s1 * 2 + s2);
            ans++;
        }

        return ans;
    }
};