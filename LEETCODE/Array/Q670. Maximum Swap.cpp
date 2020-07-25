/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++17
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximum-swap/

class Solution{
public:
    int maximumSwap(int num){
        
        string str = to_string(num);
        int pos = sortBreaker(str);
        
        if(pos == -1)
            return num;
        
        int from = getLargest(pos + 1, str);                    // scan pos to n
        int to = getReplacePos(from, pos, str);                 // scan pos to 0
        
        swap(str[from], str[to]);
        return atoi(str.c_str());
    }
    
    int getLargest(int start, string str){
        for(int i = start; i < str.size(); i++){
            if(str[i] >= str[start])                        
                start = i;
        }
        return start;
    }
    
    int getReplacePos(int from, int start, string str){
        int result = start;
        for(int i = start; i >= 0; i--){
            if(str[i] < str[from])                            
                result = i;
        }
        return result;
    }
    
    int sortBreaker(string s){
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] < s[i + 1])
                return i;
        }        
        return -1;
    }
};


/*
Approach:
    If digits are sorted in DESC order, we don't need ant swaps. We can directly return original num.
    sortBreaker() does the same.
    
    If we did not return that means array is not DESC sorted.
    We start operations form faulted-position returned by sortBreaker().
    
    -   scan whole left side from pos+1 to get the max possible digit (Y) to be replaced with some X pos.
        we find last occurance of Y.
        getLargest().
        
    -   scan whole right side from pos to get X that can be swapped with Y. (where X < Y).  
        getReplacePos().
    
    Swap (X, Y)
    Return the result.
*/

