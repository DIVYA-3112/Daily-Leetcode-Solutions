class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
        }

        int cnt = 0;
        for(auto it : mp)
        {
            if(it.second % 2 == 1) cnt++;
        }

        if(cnt > k) return false;
        if(n < k) return false;
        return true;
    }
};