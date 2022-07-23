#include <iostream>
#include "stack"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    return false;
                }
                switch (c) {
                    case ')':
                        if (stack.top() != '(') {
                            return false;
                        } else {
                            stack.pop();
                            break;
                        }
                    case ']':
                        if (stack.top() != '[') {
                            return false;
                        } else {
                            stack.pop();
                            break;
                        }
                    case '}':
                        if (stack.top() != '{') {
                            return false;
                        } else {
                            stack.pop();
                            break;
                        }
                }
            }
        }
        if (!stack.empty()) {
            return false;
        }
        return true;
    }
};
