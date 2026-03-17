/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
vector<vector<Node *>> levelOrder(Node* root) {
        queue<Node *>q;
        
        q.push(root);
        vector<vector<Node*>>ans;
        if (root == NULL)
        return ans;
        while(!q.empty()){
            int lsize=q.size();
            vector<Node *>level;
            for(int i=0; i<lsize; i++){
            Node* temp=q.front();
            q.pop();
            level.push_back(temp);
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        ans.push_back(level);
        }
        return ans;
    }
    Node* connect(Node* root) {
        vector<vector<Node *>>ans;
        
        ans=levelOrder(root);
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[i].size()-1; j++){
               //linking process
               ans[i][j]->next=ans[i][j+1];
            }
        }
        
      return root;
    }
};