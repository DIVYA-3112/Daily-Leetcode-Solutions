/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* fun(Node* node, unordered_map<int, Node*> &mp)
    {
        if(node == NULL) return NULL;

        if(mp.find(node->val) != mp.end()) return mp[node->val];

        Node* temp = new Node(node->val);
        mp[node->val] = temp;

        for(auto it : node->neighbors)
        {
            temp->neighbors.push_back(fun(it,mp));
        }

        return temp;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> mp;
        Node* root = fun(node, mp);
        return root;
    }
};