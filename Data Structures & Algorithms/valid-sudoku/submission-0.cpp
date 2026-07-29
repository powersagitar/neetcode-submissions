#include <array>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    array<unordered_set<char>, 9> subboxes;
    array<unordered_set<char>, 9> rows;
    array<unordered_set<char>, 9> cols;

    for (size_t row = 0; row < board.size(); ++row) {
      for (size_t col = 0; col < board[row].size(); ++col) {
        const char c = board[row][col];

        if (c == '.') {
          continue;
        }

        const size_t subbox = getSubbox(row, col);

        if (subboxes[subbox].count(c) > 0 || rows[row].count(c) > 0 ||
            cols[col].count(c) > 0) {
          return false;
        }

        subboxes[subbox].insert(c);
        rows[row].insert(c);
        cols[col].insert(c);
      }
    }

    return true;
  }

private:
  size_t getSubbox(const size_t row, const size_t col) {
    if (row < 3) {
      if (col < 3)
        return 0;
      else if (col < 6)
        return 1;
      else
        return 2;
    } else if (row < 6) {
      if (col < 3)
        return 3;
      else if (col < 6)
        return 4;
      else
        return 5;
    } else {
      if (col < 3)
        return 6;
      else if (col < 6)
        return 7;
      else
        return 8;
    }
  }
};
