class Solution {
public:

    long long fun(vector<int> &wt, int cnt, int ind)
    {
        int n = wt.size();
        // base case
        if(ind == n-1 && cnt == 1) return wt[ind];
        if(ind >= n || cnt <= 0) return -1e18; // Use -1e18 for very small values

        // conditions
        if(cnt % 2 == 0)
        {
            long long pick = fun(wt, cnt-1, ind) + wt[ind];
            return pick;
        }
        else if(cnt % 2 == 1)
        {
            long long pick = fun(wt, cnt-1, ind+1) + wt[ind];
            long long np = fun(wt, cnt, ind+1);
            return max(pick, np);
        }
        return 0;
    }

    long long fun2(vector<int> &wt, int cnt, int ind)
    {
        int n = wt.size();
        // base case
        if(ind == n-1 && cnt == 1) return wt[ind];
        if(ind >= n || cnt <= 0) return 1e18; // Use 1e18 for very large values

        // conditions
        if(cnt % 2 == 0)
        {
            long long pick = fun(wt, cnt-1, ind) + wt[ind];
            return pick;
        }
        else if(cnt % 2 == 1)
        {
            long long pick = fun(wt, cnt-1, ind+1) + wt[ind];
            long long np = fun(wt, cnt, ind+1);
            return min(pick, np);
        }
        return 0;
    }

    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1) return 0;
        vector<long long> pairs;
        for(int i = 0; i < n-1; i++){
            pairs.push_back(weights[i] + weights[i+1]);
        }
        sort(pairs.begin(), pairs.end());
        long long maxi = 0;
        long long mini = 0;
        for(int i = 0; i < k-1; i++){
            mini += pairs[i];
            maxi += pairs[pairs.size() - 1 - i];
        }
        return maxi - mini;
    }
};