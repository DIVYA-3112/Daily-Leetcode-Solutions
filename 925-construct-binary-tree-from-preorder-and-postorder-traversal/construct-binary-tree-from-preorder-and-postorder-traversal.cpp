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

    vector<int> pre;
    vector<int> post;
    vector<int> ind;
    TreeNode* fun(int pres, int pree, int posts, int poste)
    {
        if(pree < pres || poste < posts) return NULL;
        TreeNode *root = new TreeNode(pre[pres]);

            if(pres == pree) return root;
            else
            {
                int k = ind[pre[pres+1]];
                int ele = k - posts + 1; 
                root->left = fun(pres + 1, ele + pres, posts, k + posts);
                root->right = fun(pres + 1 + ele, pree,posts + ele, poste - 1);
            }

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        pre = preorder;
        post = postorder;
        ind.resize(n+1,-1);
        for(int i=0; i<n; i++)
        {
            ind[post[i]] = i;
        }

        TreeNode* root = fun(0,n-1,0,n-1);
        return root;
    }
};