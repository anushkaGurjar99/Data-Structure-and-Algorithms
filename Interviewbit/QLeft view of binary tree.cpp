/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/left-view-of-binary-tree/

void helper(TreeNode* node, vector<int>& result, int& targetLevel, int current){
    if(!node)
        return;
        
    if(current > targetLevel){
        targetLevel = current;
        result.push_back(node->val);
    }
    
    helper(node->left, result, targetLevel, current + 1);
    helper(node->right, result, targetLevel, current + 1);
}
 
vector<int> Solution::solve(TreeNode* A){
    int level = -1;
    vector<int> result;
    helper(A, result, level, 0);
    return result;
}

/*
Maintain a levelMarker/ targetLevel which helps in identifying which node should be considered,
    Since we want left view so we visit left subtree first then right subtree.

If current level is already visited -> skip the node
Else store the node and update the targetLevel
*/

