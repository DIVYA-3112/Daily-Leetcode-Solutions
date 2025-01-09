#define pii pair<int,int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        priority_queue<pii> pq;
        int ind = 0;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == arr[ind])
            {
                cnt++;
            }
            else
            {
                pq.push({cnt,arr[i-1]});
                ind = i;
                cnt = 1;
            }
        }
        pq.push({cnt,arr[n-1]});

        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};