/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &A){
    
    int n = A.size(); 
    
    if(n <= 1)
        return 0;
            
    int maxReachPos = A[0];
    int curMaxReachPos = A[0];
    int curStep = 1;
    
    for(int i = 1; i <= maxReachPos; i++){
        if(i == n - 1)
            return curStep;

        curMaxReachPos = max(curMaxReachPos, i + A[i]);
        if(i == maxReachPos){
            if(curMaxReachPos <= i) 
                return -1;
            maxReachPos = curMaxReachPos;
            curStep++;
        }
    }
    return -1;
}

/*
Greedy Approach:
With the current number of steps, try to maintain the maximum index which is reachable. 

When you exceed the index, you have to increase the number of steps, 
and at that instance you can increase the maximum index reachable accordingly.
*/

// *********************************************************************************************************************************
// TLE
int Solution::jump(vector<int> &A){
    
    if(A.size() == 1)
        return 0;
    
    if(A[0] == 0)
        return -1;
    
    vector<int> dp(A.size(), INT_MAX);
    dp[0] = 0;
    
    for(int i = 0; i < A.size(); i++){
        int limit = A[i];
        
        for(int j = i + 1; j <= i + limit; j++){
            dp[j] = min(dp[j], dp[i] + 1);
            if(j == A.size() - 1)
                return dp[j];
        }
        
        if(dp[i + 1] == INT_MAX && limit == 0)
            break;
    }
    
    return -1;
}
