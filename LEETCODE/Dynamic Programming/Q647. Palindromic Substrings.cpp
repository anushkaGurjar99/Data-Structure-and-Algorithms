/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/palindromic-substrings/

class Solution{
public:
    int countSubstrings(string s){
        int result = 0;
        backtrack(s, result, 0);
        return result;
    }
    
    void backtrack(string& s, int& result, int index){
        if(index == s.size())
            return;
        
        string curr;
        for(int i = index; i < s.size(); i++){
            curr.push_back(s[i]);
            if(isPalindrome(curr))
                result++;
        }
        
        backtrack(s, result, index + 1);
    }
    
    bool isPalindrome(string& s){
        int left = 0;
        int right = s.size() - 1;
        
        while(left < right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
};

/*
We need to count each possible palindrome so Scan the string linearly,
    for each outer loop char keep adding remaining char to it and check for valid palindrome.
*/


// design the DP solution

