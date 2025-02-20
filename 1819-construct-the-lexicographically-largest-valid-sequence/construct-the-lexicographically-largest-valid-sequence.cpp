class Solution {
public:

    bool fun(int n, int len, vector<int> &vis, vector<int> &ans, int ind)
    {
        if(ind == len)
        {
            return true;
        }
        if(ans[ind] != 0)
        {
            if(fun(n,len,vis,ans,ind+1)) return true;
        }
        for(int i=n; i>=1; i--)
        {
            if(vis[i] == 0 && i != 1)
            {
                if(ans[ind] == 0 && (ind+i) < len && ans[ind+i] == 0)
                {
                    // cout << ind << " - " << i << endl;
                    vis[i] = 1;
                    ans[ind] = i;
                    ans[ind+i] = i;
                    if(fun(n, len, vis, ans, ind+1)) return true;
                    ans[ind+i] = 0;
                    ans[ind] = 0;
                    vis[i] = 0;
                }
            }
            else if(vis[i] == 0 && i == 1 && ans[ind] == 0)
            {
                vis[i] = 1;
                ans[ind] = 1;
                if(fun(n, len, vis, ans, ind+1)) return true;
                ans[ind] = 0;
                vis[i] = 0;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int len = (n-1)*2 + 1;
        vector<int> vis(n+1,0);
        vector<int> ans(len,0);
        fun(n, len, vis, ans, 0);
        return ans;
    }
};