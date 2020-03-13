/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        if(nums.size() < 2)
            return 0;
        
        int i;
        int leftError = -1;
        int rightError = nums.size();

        for(i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                leftError = i;
                break;
            }
        }

        for(i = nums.size()-1 ; i > 0; i--){
            if(nums[i] < nums[i-1]){
                rightError = i;
                break;
            }
        }

        if(leftError == -1 && rightError == nums.size()){
            return 0;
        }

        int head = INT_MAX , tail = INT_MIN;
        for(i = leftError; i <= rightError; i++){
            head = min(head , nums[i]);
            tail = max(tail , nums[i]);
        }


        for(i = 0; i < leftError; i++){
            if(nums[i] > head){
                leftError = i;
                break;
            }
        }
     
        for(i = nums.size()-1; i > rightError; i--){
            if(nums[i] < tail){
                rightError = i;
                break;
            }
        }
        return rightError - leftError + 1;
    }
};

/*
We need to search for two defected elements which are causing unsorting
    loop 1 : Left border element (left)
    loop 2 : Right border element (right)
        
Then find min and max of the range (left, right), to compare the min,max with other values
    loop 3 : find min max
 
compare min with the range(start,left) that is their any other element which is less than min
same for max
    loop 4 and loop 5
    
Then return the difference
*/
