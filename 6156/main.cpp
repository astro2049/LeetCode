#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0, j = 0;
        int count = 0;
        for (; j < k; j++) {
            if (blocks[j] == 'B') {
                count++;
            }
        }
        int operations = k - count;
        while (j < blocks.length()) {
            i++, j++;
            if (blocks[i - 1] == 'B') {
                count--;
            }
            if (blocks[j - 1] == 'B') {
                count++;
            }
            operations = min(operations, k - count);
        }
        return operations;
    }
};
