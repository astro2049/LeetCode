#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int firstUniqChar(string s) {
        bool occurrenceMap[26] = {false};
        bool repeatedMap[26] = {false};
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (occurrenceMap[c - 'a']) {
                repeatedMap[c - 'a'] = true;
            }
            occurrenceMap[c - 'a'] = true;
        }
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (!repeatedMap[c - 'a']) {
                return i;
            }
        }
        return -1;
    }
};
