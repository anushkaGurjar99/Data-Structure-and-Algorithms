/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
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
// Problem Statement: https://leetcode.com/problems/serialize-and-deserialize-bst/

class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root)
            return "";
        
        return "#" + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }

    TreeNode* deserialize(string data){
        
        vector<int> nodes;
        getNodes(data, nodes);
        
        if(nodes.size() < 1)
            return nullptr;
        
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(nodes[0]);
        st.push(root);
        
        for(int i = 1; i < nodes.size(); i++){
            TreeNode* newNode = new TreeNode(nodes[i]);
            
            if(nodes[i] < st.top()->val){
                st.top()->left = newNode;
            }
            else{
                TreeNode* prev = nullptr;
                while(!st.empty() && st.top()->val < nodes[i]){
                    prev = st.top();
                    st.pop();
                }
                
                prev->right = newNode;
            }
            
            st.push(newNode);
        }
        
        return root;
    }
    
    void getNodes(string data, vector<int>& nodes){
        data += "#";      
        for(int i = 1; i < data.size(); i++){
            int num = 0;
            while(data[i] != '#'){
                num *= 10;
                num += (data[i] - '0');
                i++;
            }
            nodes.push_back(num);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

/*
Serialize using Inorder
Then Deserialize using the Approach (preorder to BST)
*/
