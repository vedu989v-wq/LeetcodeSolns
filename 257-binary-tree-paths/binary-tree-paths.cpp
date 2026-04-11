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
void paths(TreeNode *root, vector<string>&ans, string &level){
        //base condition
        if(root==NULL)
        return;

        //adding current node
        level+=(to_string(root->val)+"->");
        
        

        //checking till we get to leaf
        if(!root->left && !root->right){
        level.pop_back();
        level.pop_back();
        ans.push_back(level);

        // restoring "->" so backtracking stays consistent
        level += "->";
        
        }
       

        //recursion
        
        paths(root->left, ans, level);
        paths(root->right, ans, level);

        // backtracking :)
        int x = to_string(root->val).length() + 2;
        while(x--) 
        level.pop_back();
        
    

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string level="";
        paths(root, ans, level);
        return ans;
    }
};