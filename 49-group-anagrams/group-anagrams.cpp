class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str : strs)
        {
            string s =  str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> res;
        for(auto it : mp)
        {
            vector<string> ans;
            for(auto i : it.second)
            {
                ans.push_back(i);
            }
            res.push_back(ans);
        }
        return res;
    }
};