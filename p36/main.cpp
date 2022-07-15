#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return rowsAreValid(board) && colsAreValid(board) && subBoxesAreValid(board);
    }

    bool rowsAreValid(vector<vector<char>> board) {
        vector<bool> hashRecord(9);
        for (int y = 0; y < 9; y++) {
            fill(hashRecord.begin(), hashRecord.end(), false);
            for (int x = 0; x < 9; ++x) {
                if (board[y][x] == '.') {
                    continue;
                }
                int num = board[y][x] - '1';
                if (hashRecord[num]) {
                    return false;
                }
                hashRecord[num] = true;
            }
        }
        return true;
    }

    bool colsAreValid(vector<vector<char>> board) {
        vector<bool> hashRecord(9);
        for (int x = 0; x < 9; x++) {
            fill(hashRecord.begin(), hashRecord.end(), false);
            for (int y = 0; y < 9; ++y) {
                if (board[y][x] == '.') {
                    continue;
                }
                int num = board[y][x] - '1';
                if (hashRecord[num]) {
                    return false;
                }
                hashRecord[num] = true;
            }
        }
        return true;
    }

    bool subBoxesAreValid(vector<vector<char>> board) {
        vector<bool> hashRecord(9);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                fill(hashRecord.begin(), hashRecord.end(), false);
                for (int lilY = 0; lilY < 3; lilY++) {
                    for (int lilX = 0; lilX < 3; lilX++) {
                        if (board[i * 3 + lilY][j * 3 + lilX] == '.') {
                            continue;
                        }
                        int num = board[i * 3 + lilY][j * 3 + lilX] - '1';
                        if (hashRecord[num]) {
                            return false;
                        }
                        hashRecord[num] = true;
                    }
                }
            }
        }
        return true;
    }
};
