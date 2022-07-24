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
    bool isSymmetric(TreeNode *root) {
        return childrenAreSymmetric(root->left, root->right);
    }

    bool childrenAreSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left == nullptr || right == nullptr) {
            return false;
        } else {
            if (left->val == right->val) {
                return childrenAreSymmetric(left->left, right->right) && childrenAreSymmetric(left->right, right->left);
            } else {
                return false;
            }
        }
    }
};
