#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1;
        while (i <= s.length() / 2) {
            if (s.length() % i != 0) {
                i++;
                continue;
            }
            string subS = s.substr(i);
            bool goodMatch = true;
            for (int j = 0; j < s.length(); j++) {
                int k = j % i;
                if (subS[k] == s[j]) {
                    continue;
                } else {
                    goodMatch = false;
                    break;
                }
            }
            if (goodMatch) {
                return true;
            }
            i++;
        }
        return false;
    }
};
