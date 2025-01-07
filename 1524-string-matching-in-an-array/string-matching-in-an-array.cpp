class Solution {
public:
    bool static fun(const string& a, const string& b)
    {
        return (a.size() < b.size());
    }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), fun);
        vector<string> ans;

        for(int i=0; i<n; i++)
        {
            string s1 = words[i];
            for(int j=i+1; j<n; j++)
            {
                string s2 = words[j];
                if(s2.find(s1) != string::npos)
                {
                    ans.push_back(s1);
                    break;
                }
            }
        }
        return ans;
    }
};