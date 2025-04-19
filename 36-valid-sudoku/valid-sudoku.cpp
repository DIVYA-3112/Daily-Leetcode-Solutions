class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        int n = 9;
        for(int i=0; i<n; i++)
        {
            vector<int> vis(10,0);
            for(int j=0; j<n; j++)
            {
                char ch = board[i][j];
                if(ch == '.') continue;
                int k = (int)(ch - '0');
                // cout << k << " ";
                if(vis[k] == 1) return false;
                vis[k] = 1;
            }
            // cout << endl;
        }

        for(int j=0; j<n; j++)
        {
            vector<int> vis(10,0);
            for(int i=0; i<n; i++)
            {
                char ch = board[i][j];
                if(ch == '.') continue;
                int k = (int)(ch - '0');
                if(vis[k] == 1) return false;
                vis[k] = 1;
            }
        }

        for(int k=0; k<9; k++)
        {
            int i1 = (k%3) * 3;
            int j1 = (k/3) * 3;
            vector<int> vis(10,0);
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    char ch = board[i+i1][j+j1];
                    if(ch == '.') continue;
                    int m = (int)(ch - '0');
                    // cout << m << " ";
                    if(vis[m] == 1) return false;
                    vis[m] = 1;
                }
            }
            // cout << endl;
        }
        return true;
    }
};