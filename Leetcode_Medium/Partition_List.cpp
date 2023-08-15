/* Given the head of a linked list and a value x, partition it such that all nodes less than x 
come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]
 
Constraints:
The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200 */

using namespace std;
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* tmp = head;
        queue<int> num1;
        queue<int> num2;
        while (tmp) {
            if (tmp->val < x)
                num1.push(tmp->val);
            else
                num2.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp && !num1.empty()) {
            tmp->val = num1.front();
            num1.pop();
            tmp = tmp->next;
        }
        while (tmp && !num2.empty()) {
            tmp->val = num2.front();
            num2.pop();
            tmp = tmp->next;
        }
        return head;
    }
};