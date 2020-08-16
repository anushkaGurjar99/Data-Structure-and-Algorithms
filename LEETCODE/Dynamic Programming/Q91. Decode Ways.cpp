/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/decode-ways/

class Solution{
public:
    int numDecodings(string s){
        
        if(s.size() == 0 || s[0] == '0')
            return 0;
        
        vector<int> ways(s.size(), 1);
        
        for(int i = 1; i < s.size(); i++){
            
            if(s[i] == '0' && (s[i - 1] > '2' || s[i - 1] < '1'))
                return 0;
            
            if(s[i] == '0' || s[i - 1] == '0'){
                ways[i] = i < 2 ? 1 : ways[i - 2];
                continue;
            }
            
            int concat = (s[i - 1] - '0') * 10;
            concat += s[i] - '0';
            
            int x = i < 2 ? 1 : ways[i - 2];
            ways[i] = concat > 26 ? ways[i - 1] : ways[i - 1] + x;       
        }
        
        return ways[s.size() - 1];
    }
};


/*
Intution:
    this problem is similar to Fibo series problem except some edge cases
    
    Cases:-
        Non-Zero case:
            (*)
            if the number is compatible in concatination with prev digit 
            (which means it is comatible with both prev and prev to prev)
                then add prev 2 ways for current ways
                    1   2   1   2
                    1   2   3   5
            else   
                copy prev way for current way
                    9   9   9
                    1   1   1
                
        Zero case: 
            if zero is compatible with last digit, add its prev to prev ways (as prev is distroyed by 0)
                    1   1   1   0
                    1   2   3   2
                    
                    1 0
                    1 1     (*)

* :- if prev to prev does not exist, consider 1
*/


// ***********************************************************************************************************************************************************

class Solution{
public:
    int numDecodings(string s){
        
        int size = s.size();
        
        if(size < 1 || s[0] == '0')
            return 0;
        
        int zeroCount = 0;
        vector<int> dp(size + 1, 1);
        dp[0] = dp[1] = 1;
        
        for(int i = 1; i < size; i++){
            
            if(s[i] == '0'){
                if(s[i - 1] > '2')
                    return false;
                
                zeroCount++;
                dp[i + 1] = dp[i - 1];
            }
            else if((s[i - 1] == '1' && s[i] <= '9') || (s[i - 1] == '2' && s[i] <= '6')){
                dp[i + 1] = dp[i] + dp[i - 1];
                zeroCount = 0;
            }
            else{
                dp[i + 1] = dp[i];
                zeroCount = 0;
            }
            
            if(zeroCount == 2)
                return 0;
        }
        
        return dp[size];
    }
};

/*

    1.   1   2   1   1   2  num
    1.   1   2   3   5   8  res
    
    
cases:
    if two cont. 0                                          EX.(100)
        return 0
    if digit is 0
        if prev digit was greater than 2, return false.     EX.(1030)
        copy dp[i - 1]
    if digit is compatible with prev d                      EX.(12)
        sum dp[i - 1] + dp[i - 2]
    if digit is not compatible with prev d                  EX.(55)
        copy dp[i - 1]
*/
