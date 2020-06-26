/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++17
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/binary-search-tree-iterator/

class BSTIterator {
public:
    stack<TreeNode*> nodes;
    BSTIterator(TreeNode* root){
        while(root){
            nodes.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next(){
        TreeNode* result = nodes.top();
        nodes.pop();
        if(result->right){
            nodes.push(result->right);
            TreeNode* l = result->right->left;
            while(l){
                nodes.push(l);
                l = l->left;
            }   
        }
        
        return result->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext(){
        return nodes.size() != 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/*
Approch:
InOrder traversal using stack. 
    We are storing incre order of nodes into stack.

constructor():
    Store all left most childs into stack (initially).
    
next():
    Return top element of stack (as it is the upcoming smallest)
    If top has right child
        Store the right child of top into stack, (discard left as it has been visited already)
        Store all left most childs from top->right. (if any!)

hasnext():
    If stack size > 0, we can return next
*/

