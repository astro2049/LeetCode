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
    vector<int> pValues, qValues;

    bool isSameTree(TreeNode *p, TreeNode *q) {
        dfs(p, pValues);
        dfs(q, qValues);
        if (pValues.size() != qValues.size()) {
            return false;
        }
        for (int i = 0; i < pValues.size(); i++) {
            if (pValues[i] != qValues[i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(TreeNode* now, vector<int> &values) {
        if (now == nullptr) {
            values.push_back(-1);
            return;
        }
        values.push_back(now->val);
        dfs(now->left, values);
        dfs(now->right, values);
    }
};

class Solution2 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else {
            if (p->val == q->val) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            } else {
                return false;
            }
        }
    }
};
