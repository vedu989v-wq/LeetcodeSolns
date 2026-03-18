/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
void preorder(TreeNode* root, string &ans){
    //Module 1: Checking for 'X'
        if(root==NULL){
        ans+="X,";
        return;
        }
         
        //Module 2: Preorder recursion
        ans+=(to_string(root->val)+",");
        

        preorder(root->left,ans);
        preorder(root->right,ans);

        return ;
    }

TreeNode* construct(string &data, int &index ){
    //base condition
    
    if(index>=data.length() || data[index]=='X' ){
        index += 2;   // skip "X,"
        return NULL;
    }
    //Module 3: handling negative numbers
    int num = 0;
    bool neg = false;
     if(data[index] == '-'){   
            neg = true;
            index++;
        }

        while(index < data.length() && data[index] != ','){
            num = num * 10 + (data[index] - '0');
            index++;
        }

        if(neg) 
        num = -num;
        index++;  // skip ','

//Module 4: Main Recursion calls

        //creating temporary node for connection
        TreeNode *temp = new TreeNode(num);
    //connecting the left side
    temp->left = construct(data, index);
    //connecting the right side
    temp->right=construct(data, index);

    return temp;
}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        preorder(root, s);
        return s;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index=0;
        return construct(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));