/* Given the head of a linked list, remove the nth node from the end of the list 
and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
 
Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz    */

using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next)
            return NULL;        
        ListNode *tmp1 = head;
        ListNode *tmp2 = head;
        while (n--)
            tmp1 = tmp1->next;
        while (tmp1 && tmp1->next) {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        if (tmp2 == head && !tmp1)
            head = head->next;
        else
            tmp2->next = tmp2->next->next;    
        return head; 
    }
};