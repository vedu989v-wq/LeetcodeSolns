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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode*temp=head;
        int n=0;
        vector<int>v;
        //finding size of the linkedlist, and appending its values into an empty vector.
        while(temp){
        n++;
        v.push_back(temp->val);
        temp=temp->next;
        }
       
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && v[st.top()] < v[i]) {
                ans[st.top()] = v[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
        }

};