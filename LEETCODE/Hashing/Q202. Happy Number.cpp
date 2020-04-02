/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n){
        
        int num = n;
        string str = to_string(num);
        unordered_set<int> track;
        track.insert(num);
        
            
        while(num > 3){                         // requirement to process the string
            
            num = 0;
            for(auto curr: str)                 // calculate square of each digit add keep adding them
                num += ((curr - '0') * (curr - '0'));
            
            str = to_string(num);               // overwrite the string
            
            if(track.find(num) != track.end())  // check if num isn't creating any loop (ex : solve 4)
                break;
            else
                track.insert(num);
        }
        
        return (num == 1);                                  // num must be in range of (0 - 3)
    }
};

/*
no mater how big x is, after one step of f(x), it will be less than 810

solving 4:  {4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20}
*/
