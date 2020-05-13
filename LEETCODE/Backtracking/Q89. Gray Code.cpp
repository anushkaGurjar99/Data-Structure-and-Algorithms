/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/gray-code/

class Solution{
public:
    vector<int> grayCode(int n){
        if(n == 0)
            return {0};
        
        vector<int> result = {0, 1};
        int addOneToLeft = 0;
            
        for(int i = 1; i < n; i++){
            addOneToLeft = 1 << i;
            for(int rev = result.size() - 1; rev >= 0; rev--)
                result.push_back(addOneToLeft + result[rev]);
        }
        
        return result;
    }
};

/*
    Observation from the pattern
    
        0                       2 ^ 1
        1
        
       11                       2 ^ 2
       10
       
      110                       2 ^ 3
      111
      101
      100
      
     1100                       2 ^ 4
     1101
     1111
     1110
     1010
     1011
     1001
     1000
     
    Approach:
        Initliaze the result vector with {0, 1}
        at each level/power (start from 2...n) we does this:
            traverse the result backward (one flip at a time)
                append the new sequence into result (obtained by adding 1 to the left side of current)
                
*/

// ************************************************************************************************************************

class Solution{
public:
    vector<int> grayCode(int n){
        if(n == 0)
            return {0};
        
        int noOfElements = (1 << n);
        
		vector<int> result(noOfElements);
		
        for (int i = 0; i < noOfElements; ++i)
			result[i] = i ^ (i >> 1);
		
        return result;
    }
};
