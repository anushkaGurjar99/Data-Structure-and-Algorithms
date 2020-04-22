/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        
        priority_queue<int> values;
        
        for(auto i: nums)
            values.push(i);
        
        while(k-- > 1)
            values.pop();
        
        return values.top();
    }
};
