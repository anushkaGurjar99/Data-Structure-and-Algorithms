/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution{
private:
    struct{
        bool operator()(const int& one, const int& two){
            int setbitOne = __builtin_popcount(one);
            int setbitTwo = __builtin_popcount(two);
            
            return (setbitOne < setbitTwo) ? true : (setbitOne == setbitTwo && one < two) ? true : false; 
        }
    }comp;
    
public:
    vector<int> sortByBits(vector<int>& arr){    
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};

