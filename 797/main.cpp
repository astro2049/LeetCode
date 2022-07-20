#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, 0, graph.size() - 1, path, paths);
        return paths;
    }

    void dfs(vector<vector<int>>& graph, int currentNode, int targetNode, vector<int> path,  vector<vector<int>> &paths) {
        path.push_back(currentNode);
        if (currentNode == targetNode) {
            paths.push_back(path);
            return;
        }
        if (graph[currentNode].empty()) {
            return;
        }
        for (int i = 0; i < graph[currentNode].size(); i++) {
            dfs(graph, graph[currentNode][i], targetNode, path, paths);
        }
    }
};
