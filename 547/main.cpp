#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n + 1, false);
        int provinceCount = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinceCount++;
                dfs(i, n, isConnected, visited);
            }
        }

        return provinceCount;
    }

    void dfs(int city, int n, vector<vector<int>> isConnected, vector<bool> &visited) {
        if (visited[city]) {
            return;
        }
        visited[city] = true;
        for (int i = 0; i < n; i++) {
            if (isConnected[city][i]) {
                dfs(i, n, isConnected, visited);
            }
        }
    }
};
