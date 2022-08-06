#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string finalS = getS(s);
        string finalT = getS(t);
        return equal(finalS.begin(), finalS.end(), finalT.begin(), finalT.end());
    }

    string getS(string original) {
        string s;
        for (char c: original) {
            if (c == '#') {
                if (!s.empty()) {
                    s.pop_back();
                }
            } else {
                s.push_back(c);
            }
        }
        return s;
    }
};
