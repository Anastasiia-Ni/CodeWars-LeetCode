/* Given a list of 24-hour clock time points in "HH:MM" format, 
return the minimum minutes difference between any two time-points in the list.
 
Example 1:
Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 
Constraints:
2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM". */

using namespace std;
#include <vector>

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
       vector<int> time_min;
        for (const string &point : timePoints) {
            int hour = stoi(string(point.begin(), point.begin() + 2));
            int min = stoi(string(point.begin() + 3, point.begin() + 5));
            time_min.push_back(hour * 60 + min);
        }

        sort(time_min.begin(), time_min.end());
        int res = 24 * 60;
        int last_min = time_min[time_min.size() - 1];

        for (const int &time : time_min) {
            int dif = abs(last_min - time);
            dif = min(dif, 24 * 60 - dif);
            res = min(res, dif);
            last_min = time;
        }

        return res;
    }
};
