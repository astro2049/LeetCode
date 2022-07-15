#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0, j = letters.size() - 1;
        if (letters[j] <= target || target < letters[0]) {
            return letters[0];
        }
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (letters[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return letters[i];
    }
};
