#include <iostream>
#include "vector"

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
    TreeNode* root;
    int k;

    bool findTarget(TreeNode *root, int k) {
        this->root = root;
        this->k = k;
        return preorderTraverse(root);
    }

    bool preorderTraverse(TreeNode* now) {
        if (now == nullptr) {
            return false;
        }
        bool thisIsTheOne;
        if (k == now->val * 2) {
            thisIsTheOne = false;
        } else {
            thisIsTheOne = findPartner(root, k - now->val);
        }
        if (thisIsTheOne) {
            return true;
        } else {
            return preorderTraverse(now->left) || preorderTraverse(now->right);
        }
    }

    bool findPartner(TreeNode* now, int targetVal) {
        if (now == nullptr) {
            return false;
        }
        if (now->val == targetVal) {
            return true;
        } else {
            if (targetVal < now->val) {
                return findPartner(now->left, targetVal);
            } else {
                return findPartner(now->right, targetVal);
            }
        }
    }
};
