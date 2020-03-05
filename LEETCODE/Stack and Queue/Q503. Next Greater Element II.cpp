/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> temp;
        
        // get NGE of elements
        for(int i = 0; i < nums.size(); i++){
            if(temp.empty() || nums[temp.top()] >= nums[i]){
                temp.push(i);
            }
            else{
                while(nums[temp.top()] < nums[i]){
                    int x = temp.top();
                    res[x] = nums[i];
                    temp.pop();
                    if(temp.empty())
                        break;
                }
                temp.push(i);
            }
        }
        
        /* 
            Elements whose NGE not found in FIRST PASS will still be in temp 
            So we have to traverse nums again to find NGE of remaining elements
            Only greatest element won't have NGE, rest will definitely have.
        */
        
        if(!temp.empty()){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] > nums[temp.top()]){
                    do{
                        res[temp.top()] = nums[i];
                        temp.pop();
                        if(temp.empty())
                            return res;
                    }while(nums[i] > nums[temp.top()]);
                }
            }
        }
        return res;      
    }
};
