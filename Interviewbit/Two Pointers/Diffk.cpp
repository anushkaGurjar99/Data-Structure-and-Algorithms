/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/diffk

int Solution::diffPossible(vector<int> &A, int B){
    if(A.size() < 2)
        return 0;
        
    int slow = 0;
    int fast = 0;
    bool result = false;
    
    while(slow <= A.size() && fast <= A.size()){
        if(A[fast] - A[slow] == B && slow != fast){
            result = true;
            break;
        }
        else{
            (A[fast] - A[slow] <= B) ? ++fast : ++slow;
        }
    }
    return result;
}

/*
example :  [0  1  2  80  90] B = 79
          Iteration 1: ++fast (0,1)
          Iteration 2: ++fast (0,2)
          Iteration 3: ++fast (0,80)
          Iteration 4: ++slow (1,80)  => target found, break
*/
