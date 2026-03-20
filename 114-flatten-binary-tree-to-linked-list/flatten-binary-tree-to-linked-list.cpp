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
void preorder(TreeNode* root, TreeNode* &head){
        if(root == NULL){
            return;
        }
        
        TreeNode *temp = new TreeNode(root->val);
        head->right = temp;
        head = head->right;

        preorder(root->left, head);
        preorder(root->right, head);
    }
    
    void flatten(TreeNode* root) {
         if(root == NULL) return;

        TreeNode *head = new TreeNode(0);
        TreeNode *temp = head;

        preorder(root, head);

        temp = temp->right;

        TreeNode* curr = root;
        while(temp){
            curr->val = temp->val;
            curr->left = NULL;

            if(temp->right){
                if(curr->right == NULL){
                    curr->right = new TreeNode(0);
                }
                curr = curr->right;
            } 
            else{
                curr->right = NULL;
            }

            temp = temp->right;
        }
        
        
        
    }
};