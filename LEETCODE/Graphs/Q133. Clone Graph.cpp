/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void fillMap(Node* root, unordered_map<Node*, Node*>& m){
        if(!root){
            return;
        }
        if(m.find(root)!=m.end()){
            return;
        }
        m[root] = new Node(root->val);
        for(auto adjacent : root->neighbors){
            fillMap(adjacent, m);
        }
    }

    void connectNodes(Node* root, unordered_map<Node*, Node*>& m, unordered_set<int>& visited){
        if(!root){
            return;
        }
        
        visited.insert(root->val);

        for(auto adjacent : root->neighbors){
            
            m[root]->neighbors.push_back(m[adjacent]);
            
            if(visited.find(adjacent->val) == visited.end()){                
                connectNodes(adjacent, m, visited);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        
        fillMap(node, m);
        
        unordered_set<int> visited;
        
        connectNodes(node, m, visited);
        
        return m[node];
    }
};
