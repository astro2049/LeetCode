#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> hashmap1(1001, 0), hashmap2(1001, 0);
        for (int num : nums1) {
            hashmap1[num]++;
        }
        for (int num : nums2) {
            hashmap2[num]++;
        }
        vector<int> intersection;
        for (int i = 0; i < 1001; i++) {
            int overlapCount = min(hashmap1[i], hashmap2[i]);
            for (int j = 0; j < overlapCount; j++) {
                intersection.push_back(i);
            }
        }
        return intersection;
    }
};
