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
    void pathexistornot(TreeNode *root, int target, int &sum, bool &found){
        //base condition
        if(root==NULL || found)
        return;

        //adding current node
        sum=sum+root->val;

        //checking till we get to leaf
        if(!root->left && !root->right){
        if(sum==target)
        found=true;
        }
       

        //recursion
        pathexistornot(root->left, target, sum, found);
        pathexistornot(root->right, target, sum, found);

        //backtracking :)
        sum=sum-root->val;
    

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool chk=false;
        pathexistornot(root, targetSum, sum, chk);
        cout<<sum;
        return chk;
        
    }
};