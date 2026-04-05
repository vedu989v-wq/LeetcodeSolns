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
    ListNode* oddEvenList(ListNode* head) {
        //if no nodes, or a single node is present
        if(!head || !head->next)
        return head;
        //maintaining two predefined head, with head node as 0
        ListNode*NewHead1=new ListNode(0);
        ListNode*NewHead2=new ListNode(0);
        ListNode*curfor1=NewHead1;
        ListNode*curfor2=NewHead2;

        ListNode*temp=head;
        //Traversing the linkedList
        int h=1; //This will maintain the odd and even nodes of linked list
        while(temp){
            if(h%2==1){
                curfor1->next=temp;
                curfor1=curfor1->next;
                temp=temp->next;
            }
            else{
                curfor2->next=temp;
                curfor2=curfor2->next;
                temp=temp->next;
            }
            h++;

        }
        curfor1->next=NULL;
        curfor2->next=NULL;
        //deleting first Nodes of both of them
        temp=NewHead1;
        NewHead1=NewHead1->next;
        delete temp;

        temp=NewHead2;
        NewHead2=NewHead2->next;
        delete temp;

        //connecting these two seperated linked lists 
        curfor1->next=NewHead2;

        return NewHead1;
        
    }
};