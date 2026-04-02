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
     ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *head= new ListNode(0);
        ListNode *tail=head;
        while(head1 && head2){
            if(head2->val<=head1->val){
                tail->next=head2;
                head2=head2->next;
                tail=tail->next;
                tail->next=NULL;
            }
            else{
                tail->next=head1;
                head1=head1->next;
                tail=tail->next;
                tail->next=NULL;
            }
        }
        if(head1)
        tail->next=head1;
        else
        tail->next=head2;
        tail=head;
        head=head->next;
        delete tail;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) 
        return NULL;
        
        ListNode *head=lists[0];
        for(int i=1; i<lists.size(); i++)
        head=mergeTwoLists(head, lists[i]);
        return head;
    }
};