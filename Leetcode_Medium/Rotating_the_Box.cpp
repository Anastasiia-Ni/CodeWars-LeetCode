/* You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:
A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity.
Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. 
Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.
Return an n x m matrix representing the box after the rotation described above.

Example 1: 
Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]

Example 2:
Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]

Example 3:
Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
 
Constraints:
m == box.length
n == box[i].length
1 <= m, n <= 500
box[i][j] is either '#', '*', or '.'. */

using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int col = box.size();
        int row = box[0].size();
        vector<vector<char>> res(row, vector<char>(col, '.'));

        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                if (box[j][i] == '.') {
                    int k;
                    for (k = i; k >= 0 && box[j][k] == '.'; --k);
                    if (k >= 0 && box[j][k] == '#') {
                        res[i][col - 1 - j] = '#';
                        box[j][k] = '.';
                    }    
                }
                else {
                    res[i][col - 1 - j] = box[j][i];
                }
            }
        }

        return res;
    }
};