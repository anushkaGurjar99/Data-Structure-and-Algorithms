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

class Solution{
public:
    Node* connect(Node* root){
        if(!root)
            return nullptr;
        
        if(root->left)
            root->left->next = root->right;
        
        if(root->right && root->next)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};

// ************************* Iterative Approach *************************

class Solution{
public:
    Node* connect(Node* root){
        
        Node* curr = root;
        
        while(curr){
            Node* level = curr;
            while(level && level->left){
                level->left->next = level->right;
                if(level->next)
                    level->right->next = level->next->left;
                
                level = level->next;
            }
            curr = curr->left;
        }
        
        return root;
    }
};

// Level Order traversal (Keep completing one level in each iteration)
