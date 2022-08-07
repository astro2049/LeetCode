#include <iostream>
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> restricted;

    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        sort(restricted.begin(), restricted.end());
        this->restricted = restricted;
        vector<vector<int>> nodes(n);
        int count = 0;
        for (auto edge: edges) {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        queue<int> queue;
        queue.push(0);
        while (!queue.empty()) {
            int node = queue.front();
            visited[node] = true;
            count++;
            queue.pop();
            for (int connectedNode: nodes[node]) {
                if (visited[connectedNode]) {
                    continue;
                } else {
                    if (!binarySearch(connectedNode)) {
                        queue.push(connectedNode);
                    }
                }
            }
        }

        return count;
    }

    bool binarySearch(int target) {
        int i = 0, j = restricted.size() - 1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (restricted[mid] == target) {
                return true;
            } else if (restricted[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return false;
    }
};
