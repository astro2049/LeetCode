#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string generateTheString(int n) {
        string s;
        if (n % 2 == 0) {
            for (int i = n - 2; i >= 0; i--) {
                s.push_back('a');
            }
            s.push_back('b');
        } else {
            for (int i = n - 1; i >= 0; i--) {
                s.push_back('a');
            }
        }
        return s;
    }
};
