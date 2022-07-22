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
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (true) {
            if (fast->next == nullptr) {
                break;
            }
            fast = fast->next;
            slow = slow->next;
            if (fast->next == nullptr) {
                break;
            }
            fast = fast->next;
        }
        return slow;
    }
};
