/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

// Problem Statement: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec{
public:

    string serialize(TreeNode* root){
        if(!root)
            return "#";
        
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    TreeNode* deserialize(string data){
        vector<string> nodes;
        getNodes(data, nodes);
        int i = 0;
        return helper(nodes, i);
    }
    
    void getNodes(string& data, vector<string>& nodes){
        string curr;
        for(int i = 0; i < data.size(); i++){
            if(data[i] == ' '){
                nodes.push_back(curr);
                curr = "";
                continue;
            }
            
            if(data[i] == '#'){
                if(curr != "")
                    nodes.push_back(curr);
                curr = "";
                i++;
                nodes.push_back("#");
            }
            else{
                curr.push_back(data[i]);
            }
        }
    }
    
    TreeNode* helper(vector<string>& nodes, int& pos){
        if(nodes[pos] == "#")
            return nullptr;
        
        if(pos == nodes.size())
            return nullptr;
        
        int n = atoi(nodes[pos].c_str());
        TreeNode* newNode = new TreeNode(n);
        
        pos++;
        newNode->left = helper(nodes, pos);
        
        pos++;
        newNode->right = helper(nodes, pos);
        
        return newNode;
    }
};

/*
    (convert tree nodes into string array)
    serialize using DFS
        put # for empty nodes.
        
    (convert string into array of nodes)
    deserialize using DFS
        put null at the place of #.
*/

// ************************************************************************************************************************************************************

class Codec{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root){
        if(!root)
            return "X,";
        string leftSubtree = serialize(root->left);
        string rightSubtree = serialize(root->right);
        return to_string(root->val) + "," + leftSubtree + rightSubtree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string d){
        stringstream data(d);
        vector<string> nodes;
        string currNode;
        
        while(getline(data, currNode, ','))
            nodes.push_back(currNode);
        
        queue<string> q;
        for(auto itr: nodes)
            q.push(itr);
        
        return deserializeHelper(q);
    }
    
    TreeNode* deserializeHelper(queue<string>& q){
        string curr = q.front();
        q.pop();
        if(curr == "X")
            return nullptr;
        
        int val = atoi(curr.c_str());
        
        TreeNode* newNode = new TreeNode(val);
        newNode->left = deserializeHelper(q);
        newNode->right = deserializeHelper(q);
        
        return newNode;
    }
};

// back to back swe
