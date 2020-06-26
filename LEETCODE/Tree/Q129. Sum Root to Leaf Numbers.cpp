/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++17
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution{
public:
    int sumNumbers(TreeNode* root){
        int result = 0;
        backtrack(root, result, 0);
        return result;
    }
    
    void backtrack(TreeNode* node, int& result, int currSum){
        if(!node)
            return;
        
        currSum *= 10;
        currSum += node->val;
        
        if(!node->left && !node->right)
            result += currSum;
        
        backtrack(node->left, result, currSum);
        backtrack(node->right, result, currSum);
    }
    
};

/*
Easy backtracking.
*/

// *********************************************** Arguments Optimization ***********************************************************

class Solution{
public:
    int sumNumbers(TreeNode* root){
        return backtrack(root, 0);
    }
    
    int backtrack(TreeNode* node, int currSum){
        if(!node)
            return 0;
        
        currSum *= 10;
        currSum += node->val;
        
        int x = 0;
        if(!node->left && !node->right)
            x = currSum;
        
        return x + backtrack(node->left, currSum) + backtrack(node->right, currSum);
    }
    
};

/*
Easy backtracking.
(return type int)
*/ 
