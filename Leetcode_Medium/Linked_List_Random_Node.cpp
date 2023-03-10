/* Given a singly linked list, return a random node's value from the linked list. 
Each node must have the same probability of being chosen.
Implement the Solution class:

Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. 
All the nodes of the list should be equally likely to be chosen.

Example 1:
Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. 
Each element should have equal probability of returning.
 
Constraints:

The number of nodes in the linked list will be in the range [1, 104].
-104 <= Node.val <= 104
At most 104 calls will be made to getRandom. */

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
private:
    vector<int> my_v;

public:
    Solution(ListNode* head){
        ListNode* tmp = head;
        while (tmp) {
            my_v.push_back(tmp->val);
            tmp = tmp->next;
        }
    }
    
    int getRandom() {
        return (my_v[rand() % my_v.size()]);
    }
};
