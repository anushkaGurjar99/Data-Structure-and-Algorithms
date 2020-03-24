/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> unique;
        
        for(auto element: nums){
            if(unique.find(element) == unique.end())
                unique.insert(element);
            else
                return true;
        }
        return false;
    }
};

// Insert curr in Set and check in next iteration if curr element already exist.
