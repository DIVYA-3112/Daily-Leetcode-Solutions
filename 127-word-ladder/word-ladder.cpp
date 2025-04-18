// #define pair<int,string> pis

class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        queue<pair<int,string>> q;
        q.push({1,start});
        int n = start.size();

        unordered_map<string,int> mp;
        for(string word : wordList)
        {
            mp[word] = 1;
        }

        while(!q.empty())
        {
            auto it = q.front();
            string word = it.second;
            int len = it.first;
            if(word == end) return len;
            if(len > wordList.size()) return 0;

            q.pop();

            for(int i=0; i<n; i++)
            {
                char ch = word[i];
                for(int j=0; j<26; j++)
                {
                    word[i] = (char)(j + 'a');
                    if(mp.find(word) != mp.end())
                    {
                        mp.erase(word);
                        q.push({len + 1, word});
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};









// using DFS - Brute force TLE - TC - 23

// class Solution {
// public:

//     void dfs(string start, string end, unordered_map<string,int> &mp, unordered_map<string, int> &vis, int cnt, int &ans)
//     {
//         if(start == end)
//         {
//             ans = min(ans, cnt);
//             return;
//         }

//         int n = start.size();
//         for(int i=0; i<n; i++)
//         {
//             char old = start[i];
//             for(int j=0; j<26; j++)
//             {
//                 start[i] = (char)(j + 'a');
//                 if(mp.find(start) != mp.end() && vis[start] == 0)
//                 {
//                     vis[start] = 1;
//                     dfs(start, end, mp, vis, cnt + 1, ans);
//                     vis[start] = 0;
//                 }
//             }
//             start[i] = old;
//         }
//         return;
//     }
//     int ladderLength(string start, string end, vector<string>& wordList) {
//         unordered_map<string,int> mp;
//         for(string word : wordList)
//         {
//             mp[word] = 1;
//         }

//         unordered_map<string, int> vis;
//         vis[start] = 1;
//         int ans = INT_MAX;
//         dfs(start, end, mp, vis, 1, ans);
//         return (ans == INT_MAX) ? 0 : ans;
//     }
// };