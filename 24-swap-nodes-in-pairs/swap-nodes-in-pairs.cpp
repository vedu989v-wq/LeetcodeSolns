class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;

        ListNode* prev=NULL, *curr=head, *fut=head->next;

        // 🔧 CHANGE 1: update head once
        head = fut;

        int i=0;

        // 🔧 CHANGE 2: loop only while pair exists
        while(curr!=NULL && curr->next!=NULL){

            if(i%2==0){  // 🔧 CHANGE 3: swap on even index

                fut = curr->next;   // 🔧 CHANGE 4: always sync fut

                // swap
                curr->next = fut->next;
                fut->next = curr;

                if(prev!=NULL)      // 🔧 CHANGE 5: connect previous pair
                    prev->next = fut;

                prev = curr;        // 🔧 CHANGE 6: move prev to end of swapped pair
                curr = curr->next; // move to next pair start
            }
            i++;
        }
        return head;
    }
};