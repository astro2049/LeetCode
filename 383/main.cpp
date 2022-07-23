#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26]  = { 0 };
        for (char c : magazine) {
            map[getHash(c)]++;
        }
        for (char c : ransomNote) {
            if (map[getHash(c)] == 0) {
                return false;
            } else {
                map[getHash(c)]--;
            }
        }
        return true;
    }

    int getHash(char c) {
        return c - 'a';
    }
};
