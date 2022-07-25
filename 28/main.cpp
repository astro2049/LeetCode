#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }
        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            int j = 0, k = i;
            for (; j < needle.length(); k++, j++) {
                if (needle[j] == haystack[k]) {
                    continue;
                } else {
                    break;
                }
            }
            if (j == needle.length()) {
                return i;
            } else {
                continue;
            }
        }
        return -1;
    }
};
