#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int count = 0, res = -1;
        for (int num: nums) {
            if (count == 0) {
                res = num;
                count++;
            } else {
                if (num == res) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return res;
    }
};
