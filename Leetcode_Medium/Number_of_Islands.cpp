/* Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'. */

using namespace std;
#include <vector>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    findIsland(grid, i, j);
                }
            }
        }
        return islands;
    }

    void findIsland(vector<vector<char>>& grid, int x, int y) {
        int row = grid.size();
        int col = grid[0].size();
        
        if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == '0') {
            return;
        }

        grid[x][y] = '0';
        findIsland(grid, x - 1, y);
        findIsland(grid, x + 1, y);
        findIsland(grid, x, y - 1);
        findIsland(grid, x, y + 1);
    }
};