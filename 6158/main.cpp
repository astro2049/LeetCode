#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        vector<int> differences(s.length(), 0);
        for (auto shift: shifts) {
            int direction = shift[2] == 1 ? 1 : -1;
            int start = shift[0], end = shift[1];
            differences[start] += direction;
            differences[start] %= 26;
            if (end == s.length() - 1) {
                continue;
            } else {
                differences[end + 1] -= direction;
                differences[end + 1] %= 26;
            }
        }
        for (int i = 1; i < s.length(); i++) {
            differences[i] += differences[i - 1];
            differences[i] %= 26;
        }
        for (int i = 0; i < s.length(); i++) {
            int newAscii = s[i] + differences[i];
            if (newAscii > 'z') {
                newAscii -= 26;
            } else if (newAscii < 'a') {
                newAscii += 26;
            }
            s[i] = newAscii;
        }
        return s;
    }
};
