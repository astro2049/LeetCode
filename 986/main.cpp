#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &first, vector<vector<int>> &second) {
        vector<vector<int>> intersections;
        int i = 0, j = 0;
        while (i < first.size() && j < second.size()) {
            auto secA = first[i];
            int a = secA[0], b = secA[1];
            auto secB = second[j];
            int c = secB[0], d = secB[1];
            if (b < c) {
                i++;
            } else if (a > d) {
                j++;
            } else {
                int e = max(a, c);
                int f = min(b, d);
                intersections.push_back({e, f});
                if (b < d) {
                    i++;
                } else {
                    j++;
                }
            }
        }

        return intersections;
    }
};
