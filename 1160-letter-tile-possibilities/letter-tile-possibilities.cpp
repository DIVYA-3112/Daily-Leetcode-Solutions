class Solution {
public:

    int fun(vector<int> &mp, int size, int last)
    {
        if(size == 0 || last == 0) return 1;
        
        int ans = 0;
        for(int i=0; i<26; i++)
        {
            if(mp[i] > 0)
            {
                mp[i] -= 1;
                ans += fun(mp,size - 1,1);
                mp[i] += 1;
            }
        }

        ans += fun(mp, size, 0);
        return ans;
    }
    int numTilePossibilities(string s) {
        vector<int> mp(26,0);
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            mp[s[i] - 'A']++;
        }

        int ans = 0;
        ans = fun(mp,n,1);
        return ans - 1;
    }
};