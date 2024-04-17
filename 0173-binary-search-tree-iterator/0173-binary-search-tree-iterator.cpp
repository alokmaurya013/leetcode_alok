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
class BSTIterator {
public:
        stack<TreeNode*>s;
    TreeNode* temp;
    BSTIterator(TreeNode* root) {
      temp=root;      
    }
    int next() {
        while(temp){
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        int t=temp->val;
        temp=temp->right;
        return t;
    }
    
    bool hasNext() {
        return temp||!s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */