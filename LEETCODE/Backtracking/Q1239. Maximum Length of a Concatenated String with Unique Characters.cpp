/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution{
public:
    int maxLength(vector<string>& arr){
        int result = 0;
        unordered_set<char> s;
        backtrack(arr, s, result, 0);
        return result;
    }
    
    void backtrack(vector<string>& arr, unordered_set<char>& s, int& result, int index){
        
        result = s.size() > result ? s.size() : result;        
        if(index == arr.size())
            return;
        
        for(int i = index; i < arr.size(); i++){
            unordered_set<char> temp;
            bool flag = true;
            
            // check if string contains duplicate or string contain similat char to prev combination
            for(auto itr: arr[i]){
                if(s.find(itr) == s.end() && temp.find(itr) == temp.end())
                    temp.insert(itr);
                else{
                    flag = false;
                    break;
                }
            }
            
            if(!flag)
                continue;
            
            s.insert(temp.begin(), temp.end());                 // add string
            backtrack(arr, s, result, i + 1);
            for(auto itr: arr[i])                               // remove string
                s.erase(itr);
        }
    }    
};

/*
    - for each string check all unique combination
    - maintain a max Length
*/
