class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        unordered_map<int,int> cnt;
        unordered_map<int,int> col;

        int n = q.size();
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            int ball = q[i][0];
            int color = q[i][1];

            if(col.find(ball) != col.end())
            {
                cnt[col[ball]]--;
                if(cnt[col[ball]] == 0)
                    cnt.erase(col[ball]);
            }
            col[ball] = color;
            cnt[col[ball]]++;
            ans.push_back(cnt.size());
        }

        return ans;
    }
};