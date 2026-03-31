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
    ListNode* kreverse(ListNode* curr, ListNode* prev, int k, ListNode * &nextnode)
     {
    //Base case: return heads of required groups of k
    
        if(k==0 || curr==NULL){
        nextnode=curr;
        return prev;
        }

        ListNode* fut=curr->next;
        curr->next=prev;

        //Decrementing k, one by one, to reach to the base
        return kreverse(fut, curr, k - 1, nextnode);
    
     }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || head==NULL)
        return head;
        
        //Checking if k nodes exist
        ListNode *temp=head;

        for(int i=0; i<k; i++){
            //if nextnode becomes NULL, which means, no next node is present, so no need to recurse again, and we just have connect back the head , to head->next
            if(temp==NULL)
            return head;

            temp=temp->next;

        }
        ListNode*NextNode=NULL;
        
        //reverse first k nodes
        ListNode *NewHead=kreverse(head, NULL, k, NextNode);

        //connection with next groups
        head->next=reverseKGroup(NextNode, k);

        return NewHead;
        }
};