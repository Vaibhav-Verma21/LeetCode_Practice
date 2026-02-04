/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr!=nullptr){
            while(curr->next && curr->val == curr->next->val){
                ListNode* temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
            }
            curr=curr->next;
        }
        return head;
    }
// private:
//     ListNode* deleteNode(ListNode* head,int n){
//         if(head==NULL) return;
//         ListNode* head;
//         for(int i=i;i<n-1 && temp->next!=NULL;i++){
//             temp=temp->next;
//             if(temp == NULL || temp->next == NULL) return;
//             Node* nodeToDelete = temp->next;
//             temp->next = nodeToDelete->next;
//             delete nodeToDelete;
//         }
//     }
};