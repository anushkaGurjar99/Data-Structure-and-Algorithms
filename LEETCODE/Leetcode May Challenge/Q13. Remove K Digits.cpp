/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k){
        
        if(k == num.size())
            return "0";
        
        string number = num;
        stack<char> s;
        
        int i = 0;
        for(; i < number.size(); i++){
            char curr = number[i];
            while(!s.empty() && s.top() > curr && k-- > 0)
                s.pop();            
            
            if(k <= 0)
                break;
            
            s.push(curr);
        }
        
        number = (i == number.size()) ? "" : number.substr(i);
        
        while(!s.empty()){
            if(k > 0)
                k--;
            else
                number = s.top() + number;
            s.pop();
        }
        
        int isZero = 0;
        while(isZero < number.size() && number[isZero] == '0')
            isZero++;
        
        return isZero == number.size() ? "0" : number.substr(isZero);
    }
};

/*
    maintain a increasing stack sequence
    as soon as an element found which is smaller than top -
        remove stack element till valid k and incr property follwed
        
    restore all stack elements into result (remove leading zeros from front)
*/
