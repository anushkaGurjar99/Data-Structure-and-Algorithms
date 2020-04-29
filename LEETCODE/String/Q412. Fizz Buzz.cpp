/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n){
        vector<string> result;
        
        for(int i = 1; i <= n; i++){
            string curr = "";
            if(i % 3 == 0)
                curr += "Fizz";
            if(i % 5 == 0)
                curr += "Buzz";
            result.emplace_back(curr == "" ? to_string(i): curr);
        }
        return result;
    }
};
// String concatination

// **************************************************************************************************************

class Solution {
public:
    vector<string> fizzBuzz(int n){
        
        unordered_map<int, string> m;
        m[3] = "Fizz";
        m[5] = "Buzz";
        
        vector<string> result;
        
        for(int i = 1; i <= n; i++){
            string curr = "";
            
            for(auto itr: m){
                if(i % itr.first == 0)
                    curr = itr.second + curr;
            }
            
            result.emplace_back(curr == "" ? to_string(i): curr);
        }
        return result;
    }
};

// If you have more than Many conditions, then it will be a mess to mentionl all (use a Map instead)

