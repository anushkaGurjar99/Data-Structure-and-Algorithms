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

