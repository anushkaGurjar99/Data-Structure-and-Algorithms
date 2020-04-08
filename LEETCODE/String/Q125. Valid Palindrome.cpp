/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: 

class Solution {
public:
    bool isPalindrome(string s){
        
        int start = 0;
        int end = s.size() - 1;
        
        while(start < end){
            while(!isalnum(s[start]) && start < end)
                start++;
            
            while(!isalnum(s[end]) && start < end)
                end--;
            
            if(tolower(s[start]) != tolower(s[end]))
                return false;
            
            start++;
            end--;
        }
        
        return true;
    }
};

/*
Get the alphanumeric char from both ends then 
compare the lowerCase of both.
*/
