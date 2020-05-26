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
        vector<vector<bool>> marker(s.size(), vector<bool>(s.size(), false));
        int result = s.size();
        
        for(int i = 0; i < s.size(); i++){
            marker[i][i] = true;                                // single char is always valid palindrome
            
            for(int c = 0; c < i; c++){
                isPalindrome(marker, s, c, i);
                result += marker[c][i] ? 1 : 0;
            }
            
        }
        return result;
    }
    
    void isPalindrome(vector<vector<bool>>& marker, string& s, int start, int end){
        
        if(start + 1 < end - 1){
            if(!marker[start + 1][end - 1])
                return;
        }
        
        if(s[start] == s[end])
            marker[start][end] = true;
            //cout<<"\t"<<start<<":"<<end;
    }
};

/*
Intution:
    
    Observation -
        length 1 is always Palindrome
        length 2 must have same Characters
        length > 2, must have same border and inner substring can be checked using matrix 
    
    for each character we check all substrings before that char.
    if string > 2
        check its inner substring
    check border string
    
    store the result into marker matrix for further use.
    (true cell represent valid)
    
Example:
    "aaba"
    
            a   a   b   a
        a   1   1   0   0
        a       1   0   1
        b           1   0
        a               1
        
*/


// ****************************************************** Backtracking ******************************************************

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
    keep adding chars to string and checking for valid.
*/
