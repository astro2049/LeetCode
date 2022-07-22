#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int differentLetterCount = 0;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (differentLetterCount >= 2) {
                    return false;
                } else {
                    if (differentLetterCount == 0) {
                        index1 = i;
                    } else if (differentLetterCount == 1) {
                        index2 = i;
                    }
                    differentLetterCount++;
                }
            }
        }
        if (differentLetterCount == 0) {
            return true;
        } else if (differentLetterCount == 1) {
            return false;
        } else {
            if (s1[index1] == s2[index2] && s1[index2] == s2[index1]) {
                return true;
            } else {
                return false;
            }
        }
    }
};
