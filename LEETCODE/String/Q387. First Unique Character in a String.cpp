/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s){
        
        if(s.length() <= 1)
            return s.length() - 1;
        
        vector<int> mapp(26, -1);
        
        for(int i = 0; i < s.length(); i++){
            int index = s[i] - 'a';
            mapp[index] = (mapp[index] == -1) ? i : -2;
        }
        
        for(int i = 0; i < s.length(); i++){
            int index = s[i] - 'a';
            if(mapp[index] >= 0)
                return mapp[index];
        }
        
        return -1;
    }
};

/*
Pass one: Obtain the non-repeating by pushing non-negative index value
Pass two: Get the first +ve 
*/
