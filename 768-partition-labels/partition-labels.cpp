class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        vector<int> v(26,0);
        for(char ch : s)
        {
            mp[ch]++;
            v[ch-'a']++;
        }

        int cnt = 0;
        int cnt2 = 0;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            mp[s[i]]--;
            cnt++;
            if(mp[s[i]] == 0)
            {
                cnt2 += v[s[i]-'a'];
                v[s[i]-'a'] = 0;
                if(cnt == cnt2)
                {
                    ans.push_back(cnt);
                    cnt = 0;
                    cnt2 = 0;
                }
            }
        }
        return ans;
    }
};