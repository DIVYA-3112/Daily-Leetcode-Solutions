#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        stack<pair<TreeNode*, int>> st;  // Stack stores (TreeNode, depth)
        int i = 0, n = s.size();

        while (i < n) {
            // Count the number of dashes (depth)
            int depth = 0;
            while (i < n && s[i] == '-') {
                depth++;
                i++;
            }

            // Extract the number (it can be multi-digit)
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            // Create the new node
            TreeNode* node = new TreeNode(num);

            // Pop from stack to reach the correct parent depth
            while (!st.empty() && st.top().second >= depth) {
                st.pop();
            }

            // Attach the node to the correct parent
            if (!st.empty()) {
                if (!st.top().first->left) {
                    st.top().first->left = node;
                } else {
                    st.top().first->right = node;
                }
            }

            // Push the current node onto the stack
            st.push({node, depth});
        }

        // The root is at the bottom of the stack
        while (st.size() > 1) {
            st.pop();
        }
        return st.top().first;
    }
};
