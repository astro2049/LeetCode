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
    int val;

    TreeNode* searchBST(TreeNode* root, int val) {
        this->val = val;
        return search(root);
    }

    TreeNode* search(TreeNode* now) {
        if (now == nullptr) {
            return nullptr;
        }
        if (now->val == val) {
            return now;
        } else if (val < now->val) {
            return search(now->left);
        } else {
            return search(now->right);
        }
    }
};

class Solution2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* now = root;
        while (now != nullptr) {
            if (now->val == val) {
                return now;
            } else if (val < now->val) {
                now = now->left;
            } else {
                now = now->right;
            }
        }
        return nullptr;
    }
};
