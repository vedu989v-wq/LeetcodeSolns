class Solution {
public:
    ListNode* reverse(ListNode* curr, ListNode* prev) {
        if (curr == NULL)
            return prev;

        ListNode* fut = curr->next;
        curr->next = prev;

        return reverse(fut, curr);
    }

    ListNode* removeNodes(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        head = reverse(head, NULL);
        ListNode* temp = head;

        int currMax = head->val;

        while (temp && temp->next) {
            if (temp->next->val >= currMax) {
                currMax = temp->next->val;
                temp = temp->next;
            } else {
                ListNode* del = temp->next;
                temp->next = del->next;
                // delete del;   // removed (causes issue on LeetCode)
            }
        }

        return reverse(head, NULL);
    }
};