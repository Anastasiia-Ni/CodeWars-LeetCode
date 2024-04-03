/* Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 
Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters. */

using namespace std;
#include <vector>
#include <string>
#include <vector>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        if (row * col < word.size())
            return false;

        unordered_map<char, int> charcnt;
        for (const auto& row : board) {
            for (char ch : row) {
                charcnt[ch]++;
            }
        }
        
        for (char ch : word) {
            if (charcnt[ch] == 0) {
                return false;
            }
        }

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (dfs(r, c, 0, board, word))
                    return true;
            }
        }
        return false;
    }

    bool dfs(int r, int c, int i, vector<vector<char>>& board, string &word) {
        if (i == word.size())
            return true;
        if (r < 0 || c < 0 || r >= row || c >= col)
            return false;
        if (board[r][c] != word[i])
            return false;

        char temp = board[r][c];
        board[r][c] = '#'; 

        bool res = (dfs(r + 1, c, i + 1, board, word) ||
                    dfs(r - 1, c, i + 1, board, word) ||
                    dfs(r, c + 1, i + 1, board, word) ||
                    dfs(r, c - 1, i + 1, board, word));
        
        board[r][c] = temp;
        return res;
    }

    int row;
    int col;
};