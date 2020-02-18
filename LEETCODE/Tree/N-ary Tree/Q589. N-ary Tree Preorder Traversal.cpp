/*
 * Author : Anushka Gurjar
 * Date   : Februaruy 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Problem Statement: https://leetcode.com/problems/n-ary-tree-preorder-traversal

class Solution {
public:
    vector<int> preorder(Node* root){
        vector<int> traversal;
        if(!root)
            return traversal;
        getPreOrder(root, traversal);
        return traversal;
    }
    void getPreOrder(Node* node, vector<int>& traversal){
        if(!node)
            return;
        traversal.push_back(node->val);
        for(int i = 0; i < node->children.size(); i++)
            getPreOrder(node->children[i], traversal);
    }
};


// ************************************** Iterative Solution **************************************
class Solution {
public:
    vector<int> preorder(Node* root){
        vector<int> traversal;
        if(!root)
            return traversal;
        
        stack<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            Node* temp = nodes.top();
            nodes.pop();
            traversal.push_back(temp->val);
            for(int i = temp->children.size() - 1; i >= 0; i--)
                nodes.push(temp->children[i]);
        }
        return traversal;
    }
};
