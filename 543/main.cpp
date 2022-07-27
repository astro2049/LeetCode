#include <iostream>

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
    int diameter = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root, 0);
        return diameter;
    }

    int dfs(TreeNode* now, int height) {
        if (now == nullptr) {
            return 0;
        }
        int leftSubTreeHeight = dfs(now->left, height);
        int rightSubTreeHeight = dfs(now->right, height);
        diameter = max(diameter, leftSubTreeHeight + rightSubTreeHeight);
        return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
    }
};
