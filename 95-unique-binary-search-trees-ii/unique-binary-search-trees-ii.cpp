class Solution {
public:
    // DP table for memoization
    vector<vector<vector<TreeNode*>>> dp;

    vector<TreeNode*> generateTreesInRange(int l, int r) {
        if (l > r) return {nullptr}; // Base case: empty tree
        if (!dp[l][r].empty()) return dp[l][r]; // Return memoized result

        vector<TreeNode*> result;
        for (int i = l; i <= r; i++) {
            // Generate all left and right subtrees
            vector<TreeNode*> leftTrees = generateTreesInRange(l, i - 1);
            vector<TreeNode*> rightTrees = generateTreesInRange(i + 1, r);

            // Combine left and right subtrees with the current root `i`
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return dp[l][r] = result; // Memoize and return
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {}; // Edge case
        dp.resize(n + 1, vector<vector<TreeNode*>>(n + 1));
        return generateTreesInRange(1, n);
    }
};
