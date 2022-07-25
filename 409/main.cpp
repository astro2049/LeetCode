#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int longestPalindrome(string s) {
        int map[52] = { 0 };
        for (char c : s) {
            map[getHash(c)]++;
        }
        int length = 0;
        bool thereIsOdd = false;
        for (int i = 0; i < 52; i++) {
            if (map[i] % 2 == 0) {
                length += map[i];
            } else {
                length += (map[i] - 1);
                thereIsOdd = true;
            }
        }
        return length + thereIsOdd;
    }

    int getHash(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 26;
        } else if (c >= 'a' && c <= 'z') {
            return c - 'a';
        } else {
            return -1;
        }
    }
};
