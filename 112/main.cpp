#include <iostream>

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
    int targetSum;
    bool pathExists = false;

    bool hasPathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        dfs(root, 0);
        return pathExists;
    }

    void dfs(TreeNode* now, int currentSum) {
        if (now == nullptr) {
            return;
        }
        currentSum += now->val;
        if (now->left == nullptr && now->right == nullptr) {
            if (currentSum == targetSum) {
                pathExists = true;
            }
            return;
        }
        dfs(now->left, currentSum);
        dfs(now->right, currentSum);
    }
};
