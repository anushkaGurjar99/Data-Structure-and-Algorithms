/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

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
// Problem Statement: https://leetcode.com/problems/populating-next-right-pointers-in-each-node

class Solution {
public:
    Node* connect(Node* root){
        if(!root)
            return nullptr;
        
        if(root->left){                 // no need to check right child as its given node will have either 0 or 2 children
            root->left->next = root->right;
            if(root->next)
                root->right->next = root->next->left;
        }
        
        connect(root->left);
        connect(root->right);
        return root;
    }
};

// ************************* Iterative Approach *************************
class Solution {
public:
    Node* connect(Node* root) {
        Node *pre = root, *cur;
        while (pre) {
            cur = pre;
            while (cur && cur -> left) { 
                cur -> left -> next = cur -> right;
                if (cur -> next) {
                    cur -> right -> next = cur -> next -> left;
                }
                cur = cur -> next;
            }
            pre = pre -> left;
        }
        return root;
    }
};

