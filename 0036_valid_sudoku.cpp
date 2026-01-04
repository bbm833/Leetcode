/*
https://leetcode.com/problems/valid-sudoku/

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without
repetition. Note:

A Sudoku board (partially filled) could be valid but is not necessarily
solvable. Only the filled cells need to be validated according to the mentioned
rules.

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'

*/

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    if (isColumnsValid(board) && isRowsValid(board) && isSubBoxesValid(board)) {
      return true;
    }

    return false;
  }

  bool isRowsValid(const vector<vector<char>> &board) {
    for (int column = 0; column < 9; ++column) {
      std::unordered_set<char> numbers{};
      for (int row = 0; row < 9; ++row) {
        if (board[column][row] != '.') {
          if (numbers.find(board[column][row]) != numbers.end())
            return false;
          numbers.insert(board[column][row]);
        }
      }
    }

    return true;
  }

  bool isColumnsValid(const vector<vector<char>> &board) {
    for (int row = 0; row < 9; ++row) {
      std::unordered_set<char> numbers{};
      for (int column = 0; column < 9; ++column) {
        if (board[column][row] != '.') {
          if (numbers.find(board[column][row]) != numbers.end())
            return false;
          numbers.insert(board[column][row]);
        }
      }
    }

    return true;
  }

  bool isSubBoxesValid(const vector<vector<char>> &board) {
    for (int row = 0; row < 3; ++row) {
      for (int column = 0; column < 3; ++column) {
        std::unordered_set<char> numbers{};
        for (int i = row * 3; i < (row * 3) + 3; ++i) {
          for (int j = column * 3; j < (column * 3) + 3; ++j) {
            if (board[i][j] != '.') {
              if (numbers.find(board[i][j]) != numbers.end())
                return false;
              numbers.insert(board[i][j]);
            }
          }
        }
      }
    }

    return true;
  }
};
