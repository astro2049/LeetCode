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
    bool isValidBST(TreeNode* root) {
        return isValidTree(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }

    bool isValidTree(TreeNode* now, long long min, long long max) {
        if (!now) {
            return true;
        }
        if ((long long)now->val > min && (long long)now->val < max) {
            return isValidTree(now->left, min, now->val) && isValidTree(now->right, now->val, max);
        } else {
            return false;
        }
    }
};
