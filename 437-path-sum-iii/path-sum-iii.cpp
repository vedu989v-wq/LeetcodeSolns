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
//1)brute approach
//Module 1: Finding path from root
void pathexistornot(TreeNode *root, int target, long long int &sum, int &count){
        //base condition
        if(root==NULL)
        return;

        //adding current node
        sum=sum+root->val;

        if(sum==target)
        count++;
        
        //recursion
        
        pathexistornot(root->left, target,sum, count);
        pathexistornot(root->right, target,sum, count);

        //backtracking :)
        
        sum=sum-root->val;
    

    }
//Module 2: passing different roots to path exist or not helper, using tree traversal
int preorder(TreeNode* root, int &count, long long int &sum, int target){
        if(root==NULL)
        return -1;

        pathexistornot(root, target, sum, count);

        preorder(root->left,count, sum, target);
        preorder(root->right,count, sum, target);


        return 0;
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long int sum=0;
        int count=0;
        preorder(root, count, sum, targetSum);
        return count;
    }
};