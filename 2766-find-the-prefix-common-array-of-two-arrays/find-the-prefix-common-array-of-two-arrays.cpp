class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        unordered_map<int,int> mp;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            mp[A[i]] += 1;
            if(mp[A[i]] == 2) cnt++;

            mp[B[i]] += 1;
            if(mp[B[i]] == 2) cnt++;
            
            ans[i] = cnt;
        }
        
        return ans;
    }
};