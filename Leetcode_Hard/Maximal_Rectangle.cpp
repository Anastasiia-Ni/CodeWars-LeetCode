/* Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1: 
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1
 
Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'. */

using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size())
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector <int> hist(col, 0);
        int res = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    ++hist[j];
                }
                else {
                    hist[j] = 0;
                }
            }
            res = max (res, countRect(hist));
        }
        return res;
    }

    int countRect(const vector <int> &hist) {
        int res = 0;
        int height, width;
        stack<int> st;

        for (int i = 0; i < hist.size(); ++i) {
            while (!st.empty() && hist[i] <= hist[st.top()]) {
                height = hist[st.top()];
                st.pop();
                if (st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }
                res = max(res, height * width);
            }
            st.push(i);
        }
        while (!st.empty()) {
            height = hist[st.top()];
            st.pop();
            if (st.empty()) {
                width = hist.size();
            }
            else {
                width = hist.size() - st.top() - 1;
            }
            res = max(res, height * width);
        }

        return res;
    }
};