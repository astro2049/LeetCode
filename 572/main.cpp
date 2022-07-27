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
    TreeNode* subRoot;

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        this->subRoot = subRoot;
        return dfs(root);
    }

    bool dfs(TreeNode* now) {
        if (now == nullptr) {
            return false;
        }
        if (now->val == subRoot->val) {
            return matchSubTree(now, subRoot) || dfs(now->left) || dfs(now->right);
        } else {
            return dfs(now->left) || dfs(now->right);
        }
    }

    bool matchSubTree(TreeNode* now, TreeNode* subNow) {
        if (now == nullptr && subNow == nullptr) {
            return true;
        } else if (now == nullptr || subNow == nullptr) {
            return false;
        } else {
            if (now->val == subNow->val) {
                return matchSubTree(now->left, subNow->left) && matchSubTree(now->right, subNow->right);
            } else {
                return false;
            }
        };
    }
};
