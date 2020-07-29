/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
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
// Problem Statement: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

class Solution{
public:
    int maxDepth(Node* root){
        if(root == nullptr)
            return 0;
            
        int result = 0;
        bfs(root, result, 1);
        return result;
    }
    
    void bfs(Node* node, int& result, int currDepth){
        
        result = max(result, currDepth);
        
        if(node->children.size() == 0)
            return;
        
        for(auto itr: node->children)
            bfs(itr, result, currDepth + 1);
    }
};
