#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int sourceColor = image[sr][sc];
        if (sourceColor == color) {
            return image;
        }

        dfs(image, sr, sc, sourceColor, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int y, int x, int sourceColor, int color) {
        if (image[y][x] != sourceColor) {
            return;
        }
        image[y][x] = color;
        if (y - 1 >= 0) {
            dfs(image, y - 1, x, sourceColor, color);
        }
        if (x + 1 <= image[0].size() - 1) {
            dfs(image, y, x + 1, sourceColor, color);
        }
        if (y + 1 <=  image.size() - 1) {
            dfs(image, y + 1, x, sourceColor, color);
        }
        if (x - 1 >= 0) {
            dfs(image, y, x - 1, sourceColor, color);
        }
    }
};
