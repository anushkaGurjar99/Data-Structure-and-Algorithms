/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
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
// Problem Statement: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

class Solution{
public:
    Node* connect(Node* node){
        
        if(!node)
            return nullptr;
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* prev = nullptr;
            
            for(int i = q.size(); i > 0; i--){
                Node* curr = q.front();
                q.pop();
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
                if(prev)
                    prev->next = curr;
                prev = curr;
            }
        }
        
        return node;
    }
};

// level order traversal 
