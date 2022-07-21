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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *mergedList = new ListNode(), *dummyHead = mergedList;
        ListNode *l1Node = list1, *l2Node = list2;
        while (l1Node != nullptr && l2Node != nullptr) {
            if (l1Node->val <= l2Node->val) {
                dummyHead->next = l1Node;
                l1Node = l1Node->next;
            } else {
                dummyHead->next = l2Node;
                l2Node = l2Node->next;
            }
            dummyHead = dummyHead->next;
        }
        if (l1Node != nullptr) {
            dummyHead->next = l1Node;
        } else {
            dummyHead->next = l2Node;
        }

        return mergedList->next;
    }
};
