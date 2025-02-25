class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        unordered_map<int,int> mp;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(mp.find(A[i]) == mp.end())
            {
                mp[A[i]] = 1;
            }
            else
            {
                cnt++;
            }

            if(mp.find(B[i]) == mp.end())
            {
                mp[B[i]] = 1;
            }
            else
            {
                cnt++;
            }

            ans[i] = cnt;
        }
        return ans;
    }
};