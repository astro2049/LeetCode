#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *slow = head, *fast = head;
        while (true) {
            if (fast->next != nullptr) {
                fast = fast->next;
            } else {
                break;
            }
            if (slow == fast) {
                return true;
            }
            if (fast->next != nullptr) {
                fast = fast->next;
            } else {
                break;
            }
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
        }
        return false;
    }
};
