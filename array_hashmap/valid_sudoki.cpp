#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {

                if (board[r][c] == '.') continue;

                int value = board[r][c] - '1';

                if ((rows[r] & (1 << value)) ||
                    (cols[c] & (1 << value)) ||
                    (squares[(r / 3) * 3 + (c / 3)] & (1 << value))) {
                    return false;
                }

                rows[r] |= (1 << value);
                cols[c] |= (1 << value);
                squares[(r / 3) * 3 + (c / 3)] |= (1 << value);
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku board (9 rows, use digits 1-9 and . for empty):\n";

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;

    if (obj.isValidSudoku(board))
        cout << "Valid Sudoku\n";
    else
        cout << "Invalid Sudoku\n";

    return 0;
}
