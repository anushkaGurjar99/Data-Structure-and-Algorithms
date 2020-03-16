/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/counting-triangles

int Solution::nTriang(vector<int> &nums){
        
        if(nums.size() < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int result = 0;
        
        for(int i = nums.size() - 1; i > 0; i--){
            
            int left = 0;
            int right = i - 1;
            
            while(left < right){
                if(nums[left] + nums[right] > nums[i]){
                    result += right - left;
                    /*  If it is possible with a[l], a[r] 
                        and a[i] then it is also possible 
                        with a[l+1]..a[r-1],a[r] and a[i] */
                    
                    right--;    // checking for other elements
                }
                else{
                    left++;     // if not then check for higher value
                }
            }
        }
        
        return result;
}


// another approaches: Three pointer(sorted data), brute force  
