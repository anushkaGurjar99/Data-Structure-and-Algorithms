/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution{
public:
    vector<int> countSmaller(vector<int>& nums){
        
        int size = nums.size();
        vector<int> sorted;
        vector<int> result(size);
        
        for(int i = size - 1; i >= 0; i--){
            int pos = getPos(sorted, nums[i]);
            sorted.insert(sorted.begin() + pos, nums[i]);
            result[i] = pos;
        }
        
        return result;
    }
    
    int getPos(vector<int>& arr, int target){
        int l = 0;
        int r = arr.size() - 1;
            
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(arr[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return l;
    }
};

/*
    5   2   6   1
    
                0
            1
        1
    2
    

App1:
    construct a new array which is sorted.
    start from back of nums.
    
    each time we find element just greater than nums[i] or left most occurance of nums[i]
        update the result
            result[i] = pos that we have found.
        insert element at that pos in sorted array.
        
    time: (NlogN)
    
    Itr 1: 1                => 0
    Itr 2: 1   6            => 1
    Itr 3: 1   2   6        => 1    
    Itr 4: 1   2   5   6    => 2
*/


