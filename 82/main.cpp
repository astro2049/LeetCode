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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *previous = dummyHead;
        ListNode *now = head;
        while (now != nullptr && now->next != nullptr) {
            if (now->next->val != now->val) {
                previous = previous->next;
            } else {
                while (now->next != nullptr) {
                    if (now->next->val != now->val) {
                        break;
                    }
                    now = now->next;
                }
                previous->next = now->next;
            }
            now = now->next;
        }
        return dummyHead->next;
    }
};
