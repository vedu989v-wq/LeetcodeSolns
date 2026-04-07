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

 //commented below are all fixes than my previous code
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp){
         // use temp instead of head
            if(temp == head && temp->val == val){
                head = head->next;
                delete temp;
                temp = head;
            }
            
        
        // remove invalid NULL check (temp can’t be NULL here)
            else if(temp->val == val && temp->next == NULL){
                prev->next = NULL;   //update link before delete
                delete temp;
                temp = NULL;
            }

        else if(temp->val==val){
        prev->next=temp->next;
        delete temp;
        temp=prev->next;
        }
        else{
        prev=temp;
        temp=temp->next;
        }
        }

        return head;
    }
};