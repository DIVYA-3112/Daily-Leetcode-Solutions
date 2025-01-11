class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
            if(mp[s[i]] % 2 == 1) cnt++;
            else cnt--;
        }

        // for(auto it : mp)
        // {
        //     if(it.second % 2 == 1) cnt++;
        // }

        if(cnt > k) return false;
        if(n < k) return false;
        return true;
    }
};