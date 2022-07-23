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

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *previous = head;
        ListNode *now = head->next;
        while (now != nullptr) {
            if (now->val == previous->val) {
                previous->next = now->next;
                now = now->next;
            } else {
                previous = previous->next;
                now = now->next;
            }
        }
        return head;
    }
};
