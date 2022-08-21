#include <iostream>
#include "vector"
#include "unordered_map"
#include "queue"
#include "set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, vector<int>> nodes;

    int amountOfTime(TreeNode *root, int start) {
        nodes.insert(pair<int, vector<int>>(root->val, vector<int>()));
        traverse(root->left, root);
        traverse(root->right, root);

        return bfs(start);
    }

    void traverse(TreeNode *now, TreeNode *father) {
        if (now == nullptr) {
            return;
        }
        nodes.insert(pair<int, vector<int>>(now->val, vector<int>()));
        nodes[now->val].push_back(father->val);
        nodes[father->val].push_back(now->val);
        traverse(now->left, now);
        traverse(now->right, now);
    }

    int bfs(int start) {
        int layers = 0;
        set<int> visited;
        queue<int> qNodes;
        qNodes.push(start);
        while (!qNodes.empty()) {
            layers++;
            int layerCount = qNodes.size();
            for (int i = 0; i < layerCount; i++) {
                int nodeNum = qNodes.front();
                visited.insert(nodeNum);
                qNodes.pop();
                for (int node: nodes[nodeNum]) {
                    if (visited.find(node) == visited.end()) {
                        qNodes.push(node);
                    }
                }
            }
        }
        return --layers;
    }
};
