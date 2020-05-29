/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/counting-bits/

class Solution{
public:
    vector<int> countBits(int num){
        
        if(num == 0)
            return {0};
        
        vector<int> result(num + 1);
        result[0] = 0;
        result[1] = 1;
        int p = 1;
            
        for(int i = 2; i <= num;){
            int limit = pow(2, p++);
            for(int j = 0; j < limit; j++){
                result[i] = result[j] + 1;
                i++;
                if(i > num)
                    break;
            }
        }                
        return result;
    }
};

/*
    Base Case:
       num   set bits
        0   =   0
        1   =   1
        
    Now if you want to make further Binary numbers, visit the prev array just by adding one to set bits
    
        2   =   0 + 1
        3   =   1 + 1
        
        
    Partial array is [0,1,2,3]
    now visit again for further generations.
    
Basically each iteration produces (2^k = sizeOfPartialArray) binary bits.
*/

// ************************************************* DP Solution ***********************************************************

class Solution{
public:
    vector<int> countBits(int num){
        
        if(num == 0)
            return {0};
        
        vector<int> result(num + 1);
        result[0] = 0;
        result[1] = 1;
        int offset = 2;    
        
        for(int i = 2; i <= num; i++){
            result[i] = result[i - offset] + 1;
            if(i + 1 == offset * 2)
                offset *= 2;
        }                
        return result;
    }
};

/*
Pattern to get the general function.
    dp[0] = 0;
    dp[1] = dp[1-1] + 1;

    dp[2] = dp[2-2] + 1;
    dp[3] = dp[3-2] +1;

    dp[4] = dp[4-4] + 1;
    dp[5] = dp[5-4] + 1;
    dp[6] = dp[6-4] + 1;
    dp[7] = dp[7-4] + 1;

    dp[8] = dp[8-8] + 1;
*/

// https://leetcode.com/problems/counting-bits/discuss/79557/How-we-handle-this-question-on-interview-Thinking-process-%2B-DP-solution
