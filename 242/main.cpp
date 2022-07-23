#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int mapS[26] = { 0 };
        for (char c : s) {
            mapS[getHash(c)]++;
        }
        for (char c : t) {
            if (mapS[getHash(c)] == 0) {
                return false;
            } else {
                mapS[getHash(c)]--;
            }
        }
        return true;
    }

    int getHash(char c) {
        return c - 'a';
    }
};
