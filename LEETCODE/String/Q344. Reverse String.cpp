/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s){
        reverse(0, s.size() - 1, s);
    }
    
    void reverse(int start, int end, vector<char>& str){
        if(start < end){
            swap(str[start],str[end]);
            reverse(start + 1, end - 1, str);
        }
    }
};
//Recursive
