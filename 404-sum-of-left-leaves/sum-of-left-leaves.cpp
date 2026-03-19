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
//left view of binary tree
    void lview(TreeNode* root, vector<int>&ans ,bool lchild){
        if(!root)
        return;
        if(lchild && !root->left && !root->right)
        ans.push_back(root->val);
        
        lview(root->left, ans, 1);
        lview(root->right, ans, 0);

}
    int sumOfLeftLeaves(TreeNode* root) {
        vector<int>ans;
        int sum=0;
        lview(root, ans, 0);
        
        for(int i=0; i<ans.size(); i++){
            sum=sum+ans[i];
        }
        return sum;
    }
};