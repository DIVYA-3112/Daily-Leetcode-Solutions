class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp;
        for(string str : strs)
        {
            string s =  str;
            sort(s.begin(), s.end());
            temp.push_back(s);
        }

        unordered_map<string, vector<int>> mp;
        int i = 0;
        for(string str : temp)
        {
            mp[str].push_back(i);
            i++;
        }

        vector<vector<string>> res;
        for(auto it : mp)
        {
            vector<string> ans;
            for(auto i : it.second)
            {
                ans.push_back(strs[i]);
            }
            res.push_back(ans);
        }
        return res;
    }
};