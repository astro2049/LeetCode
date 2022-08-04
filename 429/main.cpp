#include <iostream>
#include "vector"
#include "queue"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> levels;
        if (root == nullptr) {
            return levels;
        }
        queue<Node *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int count = nodes.size();
            vector<int> level;
            for (int i = 0; i < count; i++) {
                Node *node = nodes.front();
                nodes.pop();
                level.push_back(node->val);
                for (Node *child: node->children) {
                    nodes.push(child);
                }
            }
            levels.push_back(level);
        }

        return levels;
    }
};
