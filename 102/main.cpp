#include <iostream>
#include "vector"
#include "queue"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> levels;
        if (!root) {
            return levels;
        }
        queue<TreeNode> nodes;
        nodes.push(*root);
        while (!nodes.empty()) {
            int count = nodes.size();
            vector<int> level;
            for (int i = 0; i < count; i++) {
                TreeNode node = nodes.front();
                nodes.pop();
                level.push_back(node.val);
                if (node.left != nullptr) {
                    nodes.push(*node.left);
                }
                if (node.right != nullptr) {
                    nodes.push(*node.right);
                }
            }
            levels.push_back(level);
        }
        return levels;
    }
};
