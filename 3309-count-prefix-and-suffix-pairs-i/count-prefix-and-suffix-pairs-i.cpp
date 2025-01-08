class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                string s1,s2;
                if(words[i].size() > words[j].size())
                {
                    continue;
                }
                else if(words[i].size() <= words[j].size())
                {
                    s1= words[i];
                    s2 = words[j];
                }
                
                int n1 = s1.size();
                int n2 = s2.size();

                string t1 = s2.substr(0,n1);
                string t2 = s2.substr(n2-n1,n1);

                if(t1 == s1 && t2 == s1) ans++;
            }
        }
        return ans;
    }
};