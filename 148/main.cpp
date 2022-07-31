#include <iostream>

using namespace std;

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

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode* now = head;
        int i = 0;
        while (now != nullptr) {
            now = now->next;
            i++;
        }
        return mergeSort(head, i);
    }

    ListNode* mergeSort(ListNode* head, int len) {
        if (len > 1) {
            int newLen = len / 2;
            ListNode *leftStart = head, *now = head;
            for (int i = 0; i < newLen - 1; i++) {
                now = now->next;
            }
            ListNode* rightStart = now->next;
            now->next = nullptr;
            now = rightStart;
            for (int i = 0; i < len - newLen - 1; i++) {
                now = now->next;
            }
            now->next = nullptr;
            ListNode* left = mergeSort(leftStart, newLen);
            ListNode* right = mergeSort(rightStart, len - newLen);
            return merge(left, right);
        } else {
            return head;
        }
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummyHead = new ListNode();
        ListNode* now = dummyHead;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                now->next = left;
                left = left->next;
            } else {
                now->next = right;
                right = right->next;
            }
            now = now->next;
        }
        if (left != nullptr) {
            now->next = left;
        }
        if (right != nullptr) {
            now->next = right;
        }
        return dummyHead->next;
    }
};
