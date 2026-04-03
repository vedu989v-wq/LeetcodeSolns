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
        ListNode* intersectPoint(ListNode* head1, ListNode* head2) {
        //  Code Here
        int count1=0, count2=0;
        ListNode *curr1=head1, *curr2=head2;
        while(curr1!=NULL){
        count1++;
        curr1=curr1->next;
        }
        while(curr2!=NULL){
        count2++;
        curr2=curr2->next;
        }
        int step;
        curr1=head1, curr2=head2;
        if(count1>count2){
            step=count1-count2;
            while(step){
                curr1=curr1->next;
                step--;
            }
        }
        else if(count2>=count1){
            step=count2-count1;
            while(step){
                curr2=curr2->next;
                step--;
            }
        }
        while(curr1!=curr2){
            curr1=curr1->next;
            curr2=curr2->next;
        }
        if(curr1==NULL && curr2==NULL)
        return NULL;

        return curr1;
    }

        
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==headB)
        return headA;

        return intersectPoint(headA, headB);

    }
};