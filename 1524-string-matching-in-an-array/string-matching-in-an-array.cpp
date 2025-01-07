class Solution {
public:
    // bool static fun(const string& a, const string& b)
    // {
    //     return (a.size() < b.size());
    // }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        // sort(words.begin(), words.end(), fun);
        vector<string> ans;

        for(int i=0; i<n; i++)
        {
            // string s1 = words[i];
            for(int j=0; j<n; j++)
            {
                // string s2 = words[j];
                if(i == j) continue;
                if(words[j].find(words[i]) != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};