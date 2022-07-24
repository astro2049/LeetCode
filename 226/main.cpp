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
    TreeNode* invertTree(TreeNode* root) {
        swapChilds(root);
        return root;
    }

    void swapChilds(TreeNode* now) {
        if (now == nullptr) {
            return;
        }
        TreeNode* temp = now->left;
        now->left = now->right;
        now->right = temp;
        swapChilds(now->left);
        swapChilds(now->right);
    }
};
