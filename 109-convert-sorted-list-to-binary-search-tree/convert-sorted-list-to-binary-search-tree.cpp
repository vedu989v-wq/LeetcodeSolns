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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// FIX 1: midndend should NOT take mid/end as input
// It should compute them fresh for each call
void midndend(ListNode* start, ListNode* end, ListNode* &mid, ListNode* &prev){
    ListNode* slow = start;
    ListNode* fast = start;
    prev = NULL;

    while(fast != end && fast->next != end){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    mid = slow;
}

TreeNode* listtobst( ListNode* start, ListNode* end){
    if(start==end){
        return NULL;
    }
   
    ListNode* mid;
    ListNode* prev;

    //fix: compute mid fresh
    midndend(start, end, mid, prev);

    TreeNode* root = new TreeNode(mid->val);

    // FIX 4: no need to pass mid/prev around
    root->left = listtobst(start, mid);
    root->right = listtobst(mid->next, end);
   

    return root;
    


}
   TreeNode* sortedListToBST(ListNode* head) {
    // FIX 5: just pass head and NULL as end
    return listtobst(head, NULL);
}
};