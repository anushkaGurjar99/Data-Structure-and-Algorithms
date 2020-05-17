/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/beautiful-arrangement/

class Solution{
public:
    int countArrangement(int N){
        int result = 0;
        vector<int> nums(N + 1, 0);
        iota(nums.begin(), nums.end(), 0);
        
        backtrack(nums, result, 1);
        return result;
    }
    
    void backtrack(vector<int>& nums, int& result, int index){
        if(index == nums.size()){
            result++;
            /*cout<<"\n";
            for(auto i: nums)
                cout<<" - "<<i; */
        }
        
        for(int i = index; i < nums.size(); i++){
            if(nums[i] % index == 0 || index % nums[i] == 0){
                swap(nums[i], nums[index]);
                backtrack(nums, result, index + 1);
                swap(nums[i], nums[index]);
            }
        }
    }
};

/*
Condition:
    either i is divisible by arr[i]
    or arr[i] is divisible by i
        
Approach:
    choose an index (initially 1st element)
    
    check every element from index + 1 (say i)
        if ith element satisfies obove Condition then swap both index and ith 
        backtrack form index+1 to check another arrangements
        restore the elements    
*/
