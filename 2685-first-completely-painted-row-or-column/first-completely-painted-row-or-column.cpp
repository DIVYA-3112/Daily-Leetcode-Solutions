#define pii pair<int,int>
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int ans = -1;
        unordered_map<int,pii> mp;
        int m = mat.size();
        int n = mat[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                mp[mat[i][j]] = {i,j};
            }
        }
        int k = m*n;
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        for(int i=0; i<k; i++)
        {
            auto it = mp[arr[i]];
            rows[it.first]++;
            cols[it.second]++;

            if(rows[it.first] == n || cols[it.second] == m) return i;
        }

        return ans;
    }
};