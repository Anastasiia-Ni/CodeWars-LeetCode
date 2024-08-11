/* You are given an m x n binary grid grid where 1 represents land and 0 represents water. 
An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).
Return the minimum number of days to disconnect the grid.

Example 1:
Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

Example 2:
Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.

Hint#1: Return 0 if the grid is already disconnected.
Hint#2: Return 1 if changing a single land to water disconnect the island.
Hint#3: Otherwise return 2.
Hint#4: We can disconnect the grid within at most 2 days. */

#include <vector>
using namespace std;


class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        if (isDisconnect(grid)) return 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (isDisconnect(grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }

    bool isDisconnect(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        bool foundIsland = false;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    if (foundIsland) return true;
                    dfs(grid, visited, i, j);
                    foundIsland = true;
                }
            }
        }
        return !foundIsland;
    }

    void dfs (vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return;
        if (grid[x][y] == 0 || visited[x][y] == 1) return;

        visited[x][y] = 1;
        
        dfs(grid, visited, x + 1, y);
        dfs(grid, visited, x - 1, y);
        dfs(grid, visited, x, y + 1);
        dfs(grid, visited, x, y - 1);
    }
};