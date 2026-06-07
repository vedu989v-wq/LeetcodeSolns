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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        //for parent we will mark 1, for child we will mark 0
        unordered_map<int, TreeNode*>m1;
        unordered_map<TreeNode*, bool>m2;
        

        
        for(int i=0; i<descriptions.size(); i++){
            int parent=descriptions[i][0];
            int child=descriptions[i][1];
            int isleft=descriptions[i][2];

            if(!m1.count(parent)){
                m1[parent]=new TreeNode(parent);
            }
            if(!m1.count(child)){
                m1[child]=new TreeNode(child);
            }

            if(isleft){
                m1[parent]->left=m1[child];
            }
            else{
                m1[parent]->right=m1[child];
            }

            //parent remains root, if its never been seen as a child before in its lifetime
            if(!m2.count(m1[parent]))
            m2[m1[parent]]=true;
            
            //child can never be root
            m2[m1[child]]=false;
            
        }
        TreeNode *ans;
        //traversing in m2
        for (const auto& [key, value] : m2){
            if(m2[key]==1)
            ans=key;

        }

        return ans;
    }
};