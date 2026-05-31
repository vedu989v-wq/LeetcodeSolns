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
    int pairSum(ListNode* head) {
        stack<int>st;
        int tsum=0;
        ListNode* temp=head;

        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }

        ListNode *fast, *slow;
        fast=head;
        slow=head;

        while(fast!=NULL && fast->next!=NULL){
          tsum=max(tsum, st.top()+slow->val);
          st.pop();
          slow=slow->next;
          fast=fast->next->next;
        }

        return tsum;
    }
};