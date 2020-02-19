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
// Problem Statement: https://leetcode.com/problems/n-ary-tree-postorder-traversal

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> trav;
        getPostOrder(root, trav);
        return trav;
    }
    void getPostOrder(Node* node, vector<int>& trav){
        if(!node)
            return;
        for(int i = 0; i < node->children.size(); i++)
            getPostOrder(node->children[i], trav);
        
        trav.push_back(node->val);
    }
};


// ************************************* Iterative Approach *************************************
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> trav;
        
        if(!root)
            return trav;
        
        stack<Node*> nodes;
        
        nodes.push(root);
        while(!nodes.empty()){
            Node* temp = nodes.top();
            nodes.pop();
            trav.insert(trav.begin(), temp->val);
            for(int i = 0; i < temp->children.size(); i++)
                nodes.push(temp->children[i]);
        }
        
        return trav;
    }
};
