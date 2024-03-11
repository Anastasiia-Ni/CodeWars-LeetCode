/* You are at position [0, 0] in maze NxN and you can only move in one of the four cardinal directions (i.e. North, East, South, West). 
Return the minimal number of steps to exit position [N-1, N-1] if it is possible to reach the exit from the starting position. 
Otherwise, return -1.

Empty positions are marked .. Walls are marked W. Start and exit positions are guaranteed to be empty in all test cases.
*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

vector<vector<int>> fill_matrix(string &maze) {
    vector<vector<int>> graph;
    vector<int> tmp;
    for (size_t i = 0; i < maze.size(); ++i) {
        if (maze[i] == '\n') {
            graph.push_back(tmp);
            tmp.clear();
        }
        else {
            tmp.push_back(maze[i] == 'W' ? -1 : INT_MAX);
        }
    }
    graph.push_back(tmp);
    return graph;
}

void countSteps(vector<vector<int>> &graph, int x, int y, int count) {
    if (x == -1 || y == -1)
        return;
    if (x == graph[0].size() || y == graph.size())
        return;
    if (graph[x][y] <= count)
        return;

    graph[x][y] = count;
    countSteps(graph, x, y - 1, count + 1);
    countSteps(graph, x, y + 1, count + 1);
    countSteps(graph, x + 1, y, count + 1);
    countSteps(graph, x - 1, y, count + 1);
}

int path_finder(string maze) {
    vector<vector<int>> graph;

    graph = fill_matrix(maze);
    countSteps(graph, 0, 0, 0);
    
    if (graph[graph[0].size() - 1][graph.size() - 1] == INT_MAX)
        return -1;
    return graph[graph[0].size() - 1][graph.size() - 1];
}
