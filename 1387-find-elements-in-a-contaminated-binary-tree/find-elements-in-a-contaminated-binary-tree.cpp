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
class FindElements {
public:
    TreeNode* head; 
    FindElements(TreeNode* root) {
        head = root;
    }
    
    bool find(int target) {
        vector<int> dir;
        while(target)
        {
            if(target % 2 == 0)
            {
                dir.push_back(1);
                target = (target - 2)/2;
            }
            else
            {
                dir.push_back(0);
                target = (target-1)/2;
            }
        }

            int n = dir.size();

            TreeNode* temp = head;
            int i=n-1;
            while(temp && i>=0)
            {
                if(dir[i] == 0)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
                i--;
            }

            if(i == -1 && temp) return true;
            else return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */