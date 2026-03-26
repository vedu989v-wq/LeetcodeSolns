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
void pathexistornot(TreeNode *root, int target, long long sum, int &count, unordered_map<long long,int> &mp){
        //base condition
        if(root==NULL)
        return;

        //adding current node
        sum=sum+root->val;

        if(mp.find(sum - target) != mp.end()){
            count += mp[sum - target];
        }
        
          mp[sum]++;
        
        //recursion
        
       if(root->left)
         pathexistornot(root->left, target, sum, count, mp);
       if(root->right)
         pathexistornot(root->right, target, sum, count, mp);

        // //backtracking :)
         mp[sum]--;
       
    

    }

   int pathSum(TreeNode* root, int targetSum) {
        int count=0;

        // map initialization
        unordered_map<long long,int> mp;
        mp[0] = 1;   // IMPORTANT

        // single call instead of preorder loop
        pathexistornot(root, targetSum, 0, count, mp);

        return count;
    }
};

// Why mp[0]=1?

// Handles case where:

// sum == target

// Example:

// target = 5
// sum = 5
// sum - target = 0

// So we need:

// mp[0] = 1