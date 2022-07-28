#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int count = 0;
        while (true) {
            if (count >= strs[0].size()) {
                break;
            }
            char c = strs[0][count];

            bool shouldBreak = false;
            for (int i = 1; i < strs.size(); i++) {
                string s = strs[i];
                if (count < s.size()) {
                    if (s[count] == c) {
                        continue;
                    } else {
                        shouldBreak = true;
                        break;
                    }
                } else {
                    shouldBreak = true;
                    break;
                }
            }
            if (shouldBreak) {
                break;
            } else {
                count++;
            }
        }

        return strs[0].substr(0, count);
    }
};
