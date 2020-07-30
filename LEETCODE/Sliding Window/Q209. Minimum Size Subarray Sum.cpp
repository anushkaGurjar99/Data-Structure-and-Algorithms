/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        
        int result = INT_MAX;
        int sum = 0;
        int left = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                result = min(result, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        
        return result == INT_MAX ? 0 : result;
    }
};

/*
Trav the array linearly,
    add current element into sum
    
    while sum is greater than target
        remove start element and updae start index.
        update result

return result

time: O(2N) => O(N)
*/

// two pointer sliding window approach.
