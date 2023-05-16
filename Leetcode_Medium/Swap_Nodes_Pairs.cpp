/* Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]
 
Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *node1 = head, *node2 = head;
        while (node1 && node2->next) {
            node2 = node2->next;
            int tmp = node1->val;
            node1->val = node2->val;
            node2->val = tmp;
            if (node1->next->next) {
                node1 = node1->next->next;
                node2 = node1;
            }
            else
                break;
        }
        return head;
    }
};