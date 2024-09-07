/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(TreeNode* root,ListNode* head){
        if(!root){
            return false;
        }
        if(head->val!=root->val){
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        bool l=false;
        bool r=false;
        if(head->next&&root->left&&root->left->val==head->next->val){
            l=check(root->left,head->next);
        }
        if(head->next&&root->right&&root->right->val==head->next->val){
            r=check(root->right,head->next);
        }
        return l|r;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root){
            return false;
        }
        if(head->val==root->val){
            if(check(root,head)){
                return true;
            }
        }
        return isSubPath(head,root->left)|isSubPath(head,root->right);
    }
};