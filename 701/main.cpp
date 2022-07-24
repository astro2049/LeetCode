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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* now = root;
        while (true) {
            if (val < now->val) {
                if (now->left) {
                    now = now->left;
                } else {
                    now->left = new TreeNode(val);
                    break;
                }
            } else {
                if (now->right) {
                    now = now->right;
                } else {
                    now->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
