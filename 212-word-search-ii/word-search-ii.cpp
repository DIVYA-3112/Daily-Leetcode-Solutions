class Trie
{
    public : 
    bool flag;
    Trie* data[26];

    Trie()
    {
        flag = false;
        for(int i=0; i<26; i++) data[i] = NULL;
    }

    void insert(string s)
    {
        Trie* temp = this;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(temp->data[s[i]-'a'] == NULL)
            {
                temp->data[s[i] - 'a'] = new Trie();
            }
            temp = temp->data[s[i]-'a'];
        }
        temp->flag = true;
    }
};

class Solution {
public:

    bool check(int r, int c, int m, int n)
    {
        if(r >= 0 && r < m && c >= 0 && c < n) return true;
        else return false;
    }

    void dfs(vector<vector<char>>& board, vector<vector<int>> &vis, int r, int c, Trie* temp, set<string> &ans, string word)
    {
        int m = board.size();
        int n = board[0].size();

        if(temp->flag == true) ans.insert(word);

        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for(auto [rd, cd] : dir)
        {
            int nr = r + rd;
            int nc = c + cd;

            if(check(nr, nc, m, n) && !vis[nr][nc])
            {
                if(temp->data[board[nr][nc] - 'a'] != NULL)
                {
                    vis[nr][nc] = 1;
                    dfs(board, vis, nr, nc, temp->data[board[nr][nc] - 'a'], ans, word + board[nr][nc]);
                    vis[nr][nc] = 0;
                }
            }
        }
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string word : words)
        {
            trie.insert(word);
        }

        int m = board.size();
        int n = board[0].size();
        string word = "";
        set<string> ans;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                vector<vector<int>> vis(m, vector<int>(n, 0));
                if(trie.data[board[i][j]-'a'] != NULL)
                {
                    vis[i][j] = 1;
                    dfs(board, vis, i, j, trie.data[board[i][j]-'a'], ans, word + board[i][j]);
                }
            }
        }

        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};