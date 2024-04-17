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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         string s="";
        if(!root){
            return s;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t==NULL){
                s+="?,";
            }else{
                s=s+to_string(t->val)+",";
                    q.push(t->left);
                    q.push(t->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){return NULL;}
        stringstream s(data);
        string t;
        getline(s,t,',');
        TreeNode* root=new TreeNode(stoi(t));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            getline(s,t,',');
            if(t=="?"){
                temp->left=NULL;
            }else{
                TreeNode* tmp=new TreeNode(stoi(t));
                temp->left=tmp;
                q.push(tmp);
                
            }
            getline(s,t,',');
            if(t=="?"){
                temp->right=NULL;
            }else{
                TreeNode* tmp=new TreeNode(stoi(t));
                temp->right=tmp;
                q.push(tmp);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));