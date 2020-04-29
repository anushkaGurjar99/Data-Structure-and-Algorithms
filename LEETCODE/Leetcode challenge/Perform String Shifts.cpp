/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3299/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift){
        
        for(auto itr: shift){
            s = (itr[0] == 0) ? leftShiftOnString(s, itr[1]) : rightShiftOnString(s, itr[1]); 
            //cout<<"\t"<<s;
        }   
        
        return s;
    }
    
    string leftShiftOnString(string s, int rotation){
        rotation %= s.length();
        string temp = s.substr(0, rotation);
        temp = s.substr(rotation, s.length() - rotation) + temp;
        return temp;
    }
    
    string rightShiftOnString(string s, int rotation){
        rotation %= s.length();
        string temp = s.substr(s.length() - rotation, rotation);
        temp += s.substr(0, s.length() - rotation);
        return temp;
    }
};

// just shifting according to Direction given
