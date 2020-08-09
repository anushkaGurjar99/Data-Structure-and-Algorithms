/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/2sum-binary-tree/

void helper(TreeNode* node, int& sum, unordered_set<int>& s, int& result){
    if(!node)
        return;
        
    int target = sum - node->val;
    if(s.find(target) != s.end()){
        result = 1;
        return;
    }
    
    s.insert(node->val);
    helper(node->left, sum, s, result);
    helper(node->right, sum, s, result);
}

int Solution::t2Sum(TreeNode* A, int B){
    unordered_set<int> s;
    int result = 0;
    helper(A, B, s, result);
    return result;
}

