#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isPalindrome(string s) {
        string newS;
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                newS.push_back(c - ('A' - 'a'));
            } else if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
                newS.push_back(c);
            } else {
                continue;
            }
        }
        int i = 0, j = newS.size() - 1;
        while (i < j) {
            if (newS[i] != newS[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
