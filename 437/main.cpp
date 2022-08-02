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
    int count = 0;

    int pathSum(TreeNode *root, int targetSum) {
        this->targetSum = targetSum;
        traverse(root);
        return count;
    }

    void traverse(TreeNode* now) {
        if (now == nullptr) {
            return;
        }
        look4Paths(now, 0);
        traverse(now->left);
        traverse(now->right);
    }

    void look4Paths(TreeNode* now, long long sum) {
        if (now == nullptr) {
            return;
        }
        sum += now->val;
        if (sum == targetSum) {
            this->count++;
        }
        look4Paths(now->left, sum);
        look4Paths(now->right, sum);
    }
};
