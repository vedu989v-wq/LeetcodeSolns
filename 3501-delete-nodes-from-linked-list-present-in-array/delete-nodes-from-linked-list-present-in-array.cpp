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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int>m;

        
        //Saving phase
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]=1;
        }
        //recovery phase

        ListNode *thead=new ListNode(0);
        ListNode *toi=thead;
        ListNode *temp=head;
        while(temp){
            if(!m.count(temp->val)){
              toi->next=temp;
              toi=toi->next;
            }
            temp=temp->next;
        }
        
        toi->next=NULL;
        //deleting first node in recieved linkedlist
        toi=thead;
        thead=thead->next;
        delete toi;

        return thead;

    }
};