#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zeroCount = 0;
        for (auto c: s) {
            if (c == '0') {
                zeroCount++;
            }
        }
        string finale;
        for (int i = 0; i < s.length() - zeroCount; i++) {
            finale.push_back('1');
        }
        for (int i = s.length() - zeroCount; i < s.length(); i++) {
            finale.push_back('0');
        }

        int seconds = 0;
        while (!equal(s.begin(), s.end(), finale.begin(), finale.end())) {
            seconds++;
            for (int i = 0; i < s.length() - 1; i++) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    s[i] = '1', s[i + 1] = '0';
                    i++;
                }
            }
        }

        return seconds;
    }
};
