/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/lexicographical-numbers/

class Solution{
public:
    vector<int> lexicalOrder(int n){
        vector<int> result;
        
        for(int i = 1; i <= 9; i++)
            backtrack(result, to_string(i), n);
                
        return result;
    }
    
    void backtrack(vector<int>& result, string s, int limit){
        int num = atoi(s.c_str());
        if(num > limit)
            return;
        
        result.push_back(num);
        
        num *= 10;
        s = to_string(num);
        backtrack(result, s, limit);
        
        for(int i = 1, last = s.size() - 1; i <= 9; i++){
            s[last] = s[last] + 1;
            if(s[last] <= '9')
                backtrack(result, s, limit);
        }        
    }
    
};


/*
    If number is 120, then sequence will be
    
    [1,10,100,
    101,102,103,104,105,106,107,108,109,
    11,110,111,112,113,114,115,116,117,118,119,
    12,120,13,14,15,16,17,18,19,
    
    2,20,
    21,22,23,24,25,26,27,28,29,...]

Appraoch:
  Keep multiplying the number with 10 recursivly
  Keep replacing last 0 with 1 to 9 digits recursivly
*/

// ***************************************************** More Elegant *****************************************************

class Solution{
public:
    vector<int> lexicalOrder(int n){
        vector<int> res;
        backtrack(1, n, res);
        return res;
    }
    
    void backtrack(int target, int n, vector<int>& res){
        if(target > n)
            return;
        res.push_back(target);
        backtrack(target * 10, n, res);
        if(target % 10 != 9) 
            backtrack(target+1, n, res);
    }
};

/*
Just repeatedly try from 1 to 9, 1 -> 10 -> 100 first, and then plus 1 to the deepest number. Take 13 as example:
1 -> 10 -> (100) -> 11 -> (110) -> 12 -> (120) -> 13 -> (130) -> (14) -> 2 -> (20) ... -> 9 -> (90)
*/ 

// **********************************************************************************************************************************************

class Solution{
public:
    vector<int> lexicalOrder(int n){
        vector<int> res;
        dfs(n, res, 1);    
        return res;
    }
    
    void dfs(int& limit, vector<int>& res, int num){
        if(num > limit)
            return;
        
        res.push_back(num);
        dfs(limit, res, num * 10);
        
        if(num % 10 < 9)
            dfs(limit, res, num + 1);
    }
};

/*
A1: External Sort (NlogN)
A2: Backtracking (N) 
        1
        10
        11
        12
        13
        ...
        
*/
