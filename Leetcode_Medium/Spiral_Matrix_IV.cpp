/* You are given two integers m and n, which represent the dimensions of a matrix.
You are also given the head of a linked list of integers.
Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), 
starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
Return the generated matrix.

Example 1:
Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

Example 2:
Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 
Constraints:
1 <= m, n <= 10**5
1 <= m * n <= 10** 5
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000 */

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n , -1));
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        while (head) {
            for (int i = left; head && i <= right; ++i) {
                res[top][i] = head->val;
                head = head->next;
            }
            ++top;
            for (int i = top; head && i <= bottom; ++i) {
                res[i][right] = head->val;
                head = head->next;
            }
            --right;
            for (int i = right; head && i >= left; --i) {
                res[bottom][i] = head->val;
                head = head->next;
            }
            --bottom;
            for (int i = bottom; head && i >= top; --i) {
                res[i][left] = head->val;
                head = head->next;
            }
            ++left;
        }
        return res;
    }
};