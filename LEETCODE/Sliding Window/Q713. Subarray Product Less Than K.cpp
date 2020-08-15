/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/subarray-product-less-than-k/

class Solution{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k){
        
        int result = 0;
        int start = 0;
        int product = 1;
        
        for(int i = 0; i < nums.size(); i++){
            product *= nums[i];
            
            while(start <= i && product >= k)
                product /= nums[start++];
            
            result += (i - start + 1);
        }
        
        return result;
    }
};

/*
Sliding window approach:    
    10      5       2       6

Keep mul nums[i] till window product is less than K.
As soon as product >= K
    we keep shifting window start by incr left pointer of window
Each time we calculate length of range which denotes length of Subarray.

    10          => 10           1 +
    10, 5       => 50           2 +
    [10], 5, 2  => 10           2 +
    5, 2, 6     => 60           3 = 8
    
*/

