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
#include<bits/stdc++.h>
class Solution {
public:
    Node* connect(Node* root) {
        if(!root||root->left==NULL){
            return root;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
              Node* temp=q.front();
            q.pop();
            n--;
            if(temp->left){
                q.push(temp->left);
                q.push(temp->right);
            }
            while(n--){
               Node* t=q.front();
                q.pop();
                temp->next=t;
                temp=temp->next;
                if(t->left){
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        return root;
    }
};