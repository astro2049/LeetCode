#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool wordDetected = false;
        int trailingSpaceIndex = s.length();
        int i = s.length() - 1;
        while (true) {
            if (i >= 0) {
                if (s[i] != ' ') {
                    wordDetected = true;
                } else {
                    if (wordDetected) {
                        break;
                    }
                    trailingSpaceIndex = i;
                }
                i--;
            } else {
                break;
            }
        }
        return trailingSpaceIndex - 1 - i;
    }
};
