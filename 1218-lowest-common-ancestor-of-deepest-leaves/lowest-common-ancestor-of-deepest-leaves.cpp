/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        TreeNode* temp = root;

        q.push(temp);
        set<TreeNode*> st;
        while(!q.empty())
        {
            int n = q.size();
            int cnt = 0;
            vector<TreeNode*> res;
            while(n--)
            {
                auto it = q.front();
                res.push_back(it);
                q.pop();

                if(it->left)
                {
                    q.push(it->left);
                    mp[it->left] = it;
                    cnt++;
                }

                if(it->right)
                {
                    q.push(it->right);
                    mp[it->right] = it;
                    cnt++;
                }
            }
            if(cnt == 0)
            {
                for(int i=0; i<res.size(); i++)
                {
                    st.insert(res[i]);
                }
            }
        }

        // set<TreeNode*> st(res.begin(), res.end());
        while(st.size() > 1)
        {
            set<TreeNode*> temp;
            for(auto it : st)
            {
                temp.insert(mp[it]);
            }
            st = temp;
        }
        return *st.begin();
    }
};