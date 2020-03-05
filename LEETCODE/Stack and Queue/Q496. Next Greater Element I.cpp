/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size());
        unordered_map<int, int> mapp;
        stack<int> nextG;
        
        for(int i = 0; i < nums2.size(); i++){
            if(nextG.empty() || nextG.top() >= nums2[i]){
                nextG.push(nums2[i]);
            }
            else{
                while(!nextG.empty()){
                    if(nextG.top() < nums2[i]){
                        mapp[nextG.top()] = nums2[i];
                        nextG.pop();
                    }
                    else{
                        break;
                    }
                }
                nextG.push(nums2[i]);
            }
        }
        
        for(int i = 0; i < nums1.size(); i++){
            if(mapp.count(nums1[i]) > 0)
                result[i] = mapp[nums1[i]];
            else
                result[i] = -1;
        }
        return result;
    }
};



// ************************************ Next Greater Element
        
        vector<int> res(nums.size(),-1);
        stack<int> temp;
        
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
        return res;
        
