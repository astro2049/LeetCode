#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> nums;

    vector<int> sortArray(vector<int>& nums) {
        this->nums = nums;
        quicksort(0, nums.size() - 1);
        return this->nums;
    }

    void quicksort(int leftBound, int rightBound) {
        if (leftBound < rightBound) {
            int pivotI = split(leftBound, rightBound);
            quicksort(leftBound, pivotI - 1);
            quicksort(pivotI + 1, rightBound);
        } else {
            return;
        }
    }

    int split(int leftBound, int rightBound) {
        int randomI = rand() % (rightBound - leftBound + 1) + leftBound;
        swap(nums[randomI], nums[rightBound]);
        int pivot = nums[rightBound];
        int i = leftBound - 1, j = leftBound;
        while (j < rightBound) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        i++;
        swap(nums[i], nums[rightBound]);
        return i;
    }
};
