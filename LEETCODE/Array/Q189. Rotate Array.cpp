/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
*/

// Problem Statement: https://leetcode.com/problems/rotate-array/submissions

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k){
        k = k % nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++){
            int current = start;
            int prev = nums[start];
            do{
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            }while(start != current);
        }
    }
};
