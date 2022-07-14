#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minManhattanDistance = INT32_MAX;
        int index = -1;
        for (int i = points.size() - 1; i >= 0; i--) {
            vector<int> point = points[i];
            if (point[0] == x || point[1] == y) {
                int manhattanDistance = abs(x - point[0]) + abs(y - point[1]);
                if (manhattanDistance <= minManhattanDistance) {
                    index = i;
                    minManhattanDistance = manhattanDistance;
                }
            }
        }
        return index;
    }
};
