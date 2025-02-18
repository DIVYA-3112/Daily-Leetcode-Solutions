class Solution {
public:

    bool fun(string s, string &ans, int n, vector<int>& vis)
    {
        int ind = ans.size();
        int last = ans[ind-1] - '0';
        if(ind == n+1) return true;

        if(s[ind-1] == 'I')
        {
            for(int i = last+1; i<=n+1; i++)
            {
                if(vis[i] == 0)
                {
                    vis[i] = 1;
                    ans += (char)(i + '0');
                    if(fun(s, ans, n, vis)) return true;
                    ans = ans.substr(0,ind);
                    vis[i] = 0;
                }
            }
        }
        else if(s[ind-1] == 'D')
        {
            for(int i=1 ;i<last; i++)
            {
                if(vis[i] == 0)
                {
                    vis[i] = 1;
                    ans += (char)(i + '0');
                    if(fun(s, ans, n, vis)) return true;
                    ans = ans.substr(0,ind);
                    vis[i] = 0;
                }
            }
        }
        return false;
    }
    string smallestNumber(string s) {
        string ans = "";
        int n = s.size();
        vector<int> vis(n+2,0);
        vis[0] = 1;
        for(int i=1; i<=n+1; i++)
        {
            vis[i] = 1;
            ans += (char)(i + '0');
            if(fun(s,ans,n,vis)) return ans;
            ans = ans.substr(0,0);
            vis[i] = 0;
        }
        return ans;

    }
};