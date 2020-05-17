/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/palindrome-partitioning/

class Solution{
public:
    vector<vector<string>> partition(string s){   
        vector<vector<string>> result;
        backtrack(s, result, {}, 0);
        return result;
    }
    
    void backtrack(string& s, vector<vector<string>>& result, vector<string> curr, int index){
        
        if(index == s.size()){
            result.push_back(curr);
            return;
        }
        
        string seq = "";
        for(int i = index; i < s.size(); i++){
            seq.push_back(s[i]);
            if(isPalindrome(seq)){
                curr.push_back(seq);
                backtrack(s, result, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& str){
        int left = 0;
        int right = str.size() - 1;
        
        while(left < right){
            if(str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

/*
Intution:
    we know that each individual letter in a valid palindrome, 
    so first we recurse through all elements and push the sequence into result.
    
    backtracking - 
    then we keep adding next char to our current string ("c") till it reaches to end.
        if it is a palinfrome then we store "c" into array and recurse from its next element
        else we keep adding element to "c" 
*/
