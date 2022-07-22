#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> values;
        if (root == nullptr) {
            return values;
        }
        dfs(root, values);
        return values;
    }

    void dfs(Node* node, vector<int>& values) {
        values.push_back(node->val);
        if (node->children.empty()) {
            return;
        }
        for (Node* child : node->children) {
            dfs(child, values);
        }
    }
};
