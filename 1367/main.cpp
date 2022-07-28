#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* head;
    bool isSubPathMarker = false;

    bool isSubPath(ListNode *head, TreeNode *root) {
        this->head = head;
        traverse(root);
        return isSubPathMarker;
    }

    void traverse(TreeNode* now) {
        if (now == nullptr) {
            return;
        }
        if (now->val == head->val) {
            if (tryMatch(now, head)) {
                isSubPathMarker = true;
            }
        }
        traverse(now->left);
        traverse(now->right);
    }

    bool tryMatch(TreeNode *now, ListNode* listNow) {
        if (listNow == nullptr) {
            return true;
        } else {
            if (now == nullptr) {
                return false;
            } else {
                if (now->val == listNow->val) {
                    return tryMatch(now->left, listNow->next) || tryMatch(now->right, listNow->next);
                } else {
                    return false;
                }
            }
        }
    }
};
