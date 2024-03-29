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
    bool isBalancedMarker = true;

    bool isBalanced(TreeNode *root) {
        traverse(root);
        return isBalancedMarker;
    }

    int traverse(TreeNode *now) {
        if (now == nullptr) {
            return 0;
        }
        int leftSubTreeHeight = traverse(now->left);
        int rightSubTreeHeight = traverse(now->right);
        if (abs(leftSubTreeHeight - rightSubTreeHeight) > 1) {
            isBalancedMarker = false;
        }
        return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
    }
};
