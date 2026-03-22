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
void preorderndshiftadder(TreeNode* root, int &sum, int &netsum ){
        if(root==NULL)
        return;

        //2)shift adding
        sum=sum*10+root->val;
        
        if(!root->left && !root->right){
            netsum=netsum+sum;
            }
        

        preorderndshiftadder(root->left,sum, netsum);
        preorderndshiftadder(root->right,sum, netsum);

        //3)backtracking
        
        sum=sum/10;

        
    }
    int sumNumbers(TreeNode* root) {
        int netsum, sum;
        netsum=0;
        sum=0;
        
        preorderndshiftadder(root, sum, netsum);
        return netsum;

    }
};