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
void pathexistornot(TreeNode *root, int target, int &sum, vector<vector<int>>&ans, vector<int>&level){
        //base condition
        if(root==NULL)
        return;

        //adding current node
        level.push_back(root->val);
        sum=sum+root->val;

        //checking till we get to leaf
        if(!root->left && !root->right){
        if(sum==target)
        ans.push_back(level);
        }
       

        //recursion
        
        pathexistornot(root->left, target,sum,  ans, level);
        pathexistornot(root->right, target,sum, ans, level);

        //backtracking :)
        level.pop_back();
        sum=sum-root->val;
    

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>level;
        int sum=0; 
        pathexistornot(root, targetSum, sum,ans, level);
        return ans;
    }
};