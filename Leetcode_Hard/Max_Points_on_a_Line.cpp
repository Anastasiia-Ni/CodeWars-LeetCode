/* Given an array of points where points[i] = [xi, yi] represents a point
on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 
Constraints:
1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique. */

using namespace std;
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int maxPoints(vector<vector<int> >& points) {
        int res = 0;

        if(points.size() < 2) 
            return points.size();
        for (int i = 0; i < points.size(); i++) {
            map <pair<int, int>, int> line;
            int lap = 0;
            int vert = 0;
            int lmax = 0;
            
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
                    lap++;
                else if (points[j][0] == points[i][0])
                    vert++;
                else {
                    int x = points[j][0] - points[i][0];
                    int y = points[j][1] - points[i][1];
                    int nod = NOD(x,y);
                    x /= nod;
                    y /= nod;
                    line[{x, y}]++;
                    lmax = max(line[{x, y}], lmax);
                }
                lmax = max(vert, lmax);
            }
            res = max(res, lmax + lap + 1);
        }
        return res;
    }

    int NOD(int x, int y) {
        return (y == 0 ? x : NOD(y, x % y));
    }
};


