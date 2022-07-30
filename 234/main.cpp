#include <iostream>
#include "vector"

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
    bool isPalindrome(ListNode *head) {
        ListNode* now = head;
        vector<int> values;
        while (now != nullptr) {
            values.push_back(now->val);
            now = now->next;
        }
        int i = 0, j = values.size() - 1;
        while (i < j) {
            if (values[i] != values[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }
};
