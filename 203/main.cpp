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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *nowNode = dummyHead;
        while (nowNode->next != nullptr) {
            if (nowNode->next->val== val) {
                if (nowNode->next->next != nullptr) {
                    nowNode->next = nowNode->next->next;
                } else {
                    nowNode->next = nullptr;
                    break;
                }
            } else {
                nowNode = nowNode->next;
            }
        }
        return dummyHead->next;
    }
};
