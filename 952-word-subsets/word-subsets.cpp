class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words2.size();
        // unordered_map<char,int> mp;
        vector<int> maxfreq(26,0);
        for(string s : words2)
        {
            int k = s.size();
            vector<int> temp(26,0);
            for(int j=0; j<k; j++)
            {
                temp[s[j] - 'a']++;
            }

            for(int i=0; i<26; i++)
            {
                maxfreq[i] = max(maxfreq[i], temp[i]);
            }
        }
        int cnt = 0;
        for(int i=0; i<26; i++)
        {
            if(maxfreq[i] != 0)
            {
                cout << (char)(i + 'a') << " - " << maxfreq[i] << endl;
                cnt += maxfreq[i]; 
            }
        }
        cout << "cnt - " << cnt << endl;

        // return {""};
        vector<string> ans;
        for(string s : words1)
        {
            vector<int>temp = maxfreq;
            int k = s.size();
            int count = 0;
            for(int i=0; i<k; i++)
            {
                if(temp[s[i] - 'a'] > 0)
                {
                    temp[s[i] - 'a']--;
                    count++;
                }
            }
            temp = maxfreq;
            if(cnt == count) ans.push_back(s);
        }
        return ans;
    }
};