/* Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

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
        if (!head || !head->next)
            return head;

        ListNode* newHead = head->next;
        ListNode* prev = nullptr;

        while (head && head->next) {
            ListNode* cur1 = head;
            ListNode* cur2 = head->next;

            cur1->next = cur2->next;
            cur2->next = cur1;

            if (prev) {
                prev->next = cur2;
            }

            prev = cur1;
            head = cur1->next;
        }
        return newHead;
    }
};