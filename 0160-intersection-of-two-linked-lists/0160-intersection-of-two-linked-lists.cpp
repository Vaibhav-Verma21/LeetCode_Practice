/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> stackA, stackB;

        while (headA) {
            stackA.push(headA);
            headA = headA->next;
        }

        while (headB) {
            stackB.push(headB);  
            headB = headB->next;
        }

        ListNode* intersect = nullptr;
        while (!stackA.empty() && !stackB.empty()) {
            ListNode* nodeA = stackA.top();
            ListNode* nodeB = stackB.top();
            stackA.pop();
            stackB.pop();

            if (nodeA == nodeB) {
                intersect = nodeA;
            } else {
                break;
            }
        }

        return intersect;
    }
};
