class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26,0);
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            v[s[i]-'a']++;
        }

        int i=0, j=n-1;

        while(j>i)
        {
            for(int k=0; k<26; k++)
            {
                char ch = (char)(k+'a');
                while(v[k] > 1)
                {
                    s[i] = ch;
                    s[j] = ch;
                    v[k] -= 2;
                    i++;
                    j--;
                }
                if(v[k] == 1)
                {
                    s[n/2] = ch;
                    v[k]--;
                }
            }
        }
        return s;
    }
};