/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/remove-half-nodes/

TreeNode* Solution::solve(TreeNode* A){
    if(!A)
        return nullptr;
        
    A->left = solve(A->left);
    A->right = solve(A->right);
    
    if(!A->left && !A->right)
        return A;
        
    if(!A->left)
        return A->right;
    
    if(!A->right)
        return A->left;
        
    return A;
}

/*
1 2 3 -1 -1 4 -1 -1 5 -1 -1

                1
            2       3
                  4
                      5
                      
                =>
                
                1
             2     5
*/
