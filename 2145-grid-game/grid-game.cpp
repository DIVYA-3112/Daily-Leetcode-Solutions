class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid[0].size();
        long long sum1 = 0;
        long long sum0 = 0;
        for(int i=0; i<m; i++)
        {
            sum0 += grid[0][i];
            sum1 += grid[1][i];
        }

        long long nsum0 = grid[0][0];
        long long nsum1 = sum1;
        long long sum = sum1 + nsum0;
        long long ans = sum0 - nsum0;
        for(int i=1; i<m; i++)
        {
            nsum1 -= grid[1][i-1];
            nsum0 += grid[0][i];
            long long nsum = nsum0 + nsum1;
            ans = min(ans,max(sum0 - nsum0, sum1 - nsum1));
            // cout << sum << endl;
        }
        return ans;
    }
};