/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/jump-game-ii/

class Solution{
public:
    int jump(vector<int>& A) {
        
        int n = A.size(); 
    
        if(n <= 1)
            return 0;

        int limit = A[0];
        int curMaxReachPos = A[0];
        int curStep = 1;

        for(int i = 1; i <= limit; i++){
            if(i == n - 1)
                break;

            curMaxReachPos = max(curMaxReachPos, i + A[i]);
            
            if(i == limit){
                limit = curMaxReachPos;
                curStep++;
            }
        }
        
        return curStep;
    }
};

/*
Greedy Approach:
With the current number of steps, try to maintain the maximum index which is reachable.

When you exceed the index, 
you have to increase the number of steps, which we have found in currMaxReachPos.
*/
