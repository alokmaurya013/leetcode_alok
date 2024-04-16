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
#include<bits/stdc++.h>
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;
        if(depth==1){
            TreeNode* t=new TreeNode(val);
            t->left=root;
            root=t;
            return root;
        }
        
        int c=1;
        q.push(root);
        while(!q.empty()&&c<depth){
            int n=q.size();
            c++;
            while(n--){
                TreeNode* t=q.front();
                q.pop();
                if(c==depth){
                    if(t->left){
                          TreeNode* tn=new TreeNode(val);
                        TreeNode* temp=t->left;
                        t->left=tn;
                        tn->left=temp;
                    }else{
                         TreeNode* tn=new TreeNode(val);
                        t->left=tn;
                    }
                    if(t->right){
                          TreeNode* tn=new TreeNode(val);
                        TreeNode* temp=t->right;
                        t->right=tn;
                        tn->right=temp;
                    }else{
                          TreeNode* tn=new TreeNode(val);
                        t->right=tn;
                    }
                }else{
                    if(t->left){
                        q.push(t->left);
                    }
                    if(t->right){
                        q.push(t->right);
                    }
                }
            }
        }
        return root;
    }
};