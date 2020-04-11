/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-palindrome/

#include<stdio.h>

class Solution{
public:
    int longestPalindrome(string s){
        
        if(s.length() == 0)
            return 0;
        
        unordered_map<char, int> freq;
        
        for(auto i: s)
            freq[i]++;
        
        int odd = 0;
        int count = 0;
        
        for(auto f: freq){
            
            int curr = f.second;
            if(curr % 2 == 0){
                count += curr;
            }
            else{
                count += (curr - 1);
                odd = 1;
            }
            
        }
        count += odd;
        
        return count;
    }
};

/*
Approach: 
    Count frequency of each Character;
    
    Iterate through frequencies
        If frequency is even keep adding it into result.            (as we can have it both side) 
        Else add atMost count (f-1) of odd frequency (mark isOdd true so that 1 can be added later)
        
    Add the maximum odd frequence into result.    
*/
