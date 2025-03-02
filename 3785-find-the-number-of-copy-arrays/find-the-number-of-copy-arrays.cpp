class Solution {
public:
    int countArrays(vector<int>& ori, vector<vector<int>>& bou) {
        int n = ori.size(); 
        int s = bou[0][0];
        int e = bou[0][1];

        for(int i=0; i<n-1; i++)
        {
            int ns = ori[i+1] - ori[i] + s;
            int ne = ori[i+1] - ori[i] + e;

            s = max(ns, bou[i+1][0]);
            e = min(ne, bou[i+1][1]);
        }

        return max(0,(e-s+1));
    }
};