/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3289/

class Solution {
public:
    int countElements(vector<int>& arr){
        
        unordered_set<int> elements;
        int result = 0;
        
        for(auto curr: arr)
            elements.insert(curr);
        
        
        for(auto curr: arr){
            if(elements.find(curr + 1) != elements.end())
                result++;
        }
        
        return result;
    }
};

/*
Pass 1: Store all elements into Set
Pass 2: Check occurance of n+1 into Set
*/
