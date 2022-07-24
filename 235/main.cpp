#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode* now = root;
        while (now != nullptr) {
            if ((p->val < now->val && q->val > now->val) || (p->val > now->val && q->val < now->val)) {
                return now;
            } else if (p->val < now->val && q->val < now->val) {
                now = now->left;
            } else if (p->val > now->val && q->val > now->val) {
                now = now->right;
            } else {
                if (p->val == now->val) {
                    return p;
                } else {
                    return q;
                }
            }
        }
        return nullptr;
    }
};
