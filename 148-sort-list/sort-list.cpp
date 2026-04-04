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
    ListNode* sortList(ListNode* head) {
        vector<pair<ListNode*, int>>v;

        ListNode *NewHead=new ListNode(0);
        ListNode *curr=NewHead;
        ListNode *temp=head;
        while(temp!=NULL){
            v.push_back({temp, temp->val});
            temp=temp->next;
        }
        //sorting the vector, in ascending order
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    //Linking the pairs back again
    for(int i=0; i<v.size(); i++){
        curr->next=v[i].first;
        curr=curr->next;
    }
    curr->next = NULL;
    //deleting head node, 0
    temp=NewHead;
    NewHead=NewHead->next;
    delete temp;

    return NewHead;


    }
};