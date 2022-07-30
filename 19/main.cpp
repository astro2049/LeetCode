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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* previous = dummyHead;
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            previous = previous->next;
            fast = fast->next;
        }
        previous->next = previous->next->next;
        return dummyHead->next;
    }
};
