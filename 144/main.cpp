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
    vector<int> values;

    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *now = root;
        visit(now);
        return values;
    }

    void visit(TreeNode* now) {
        if (now == nullptr) {
            return;
        }
        values.push_back(now->val);
        visit(now->left);
        visit(now->right);
    }
};
