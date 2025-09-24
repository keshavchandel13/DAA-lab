#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> results;

bool is_safe(vector<string>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    // Check upper-left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    // Check upper-right diagonal
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void backtrack(vector<string>& board, int row, int n) {
    if (row == n) {
        results.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col, n)) {
            board[row][col] = 'Q';
            backtrack(board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0, n);
    return results;
}

int main() {
    int n = 4;
    auto solutions = solveNQueens(n);

    for (auto& board : solutions) {
        for (auto& row : board)
            cout << row << "\n";
        cout << "\n";
    }
}
