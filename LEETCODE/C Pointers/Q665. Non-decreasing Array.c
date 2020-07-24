/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/non-decreasing-array/

bool checkPossibility(int* nums, int numsSize){
    
    int counter = 0;
    int cur = 0;
    
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] > nums[i + 1]){
            counter++;
            cur = i;
        }
    }

    if(counter >= 2) 
        return false;
    
    if(cur == 0 || cur == numsSize - 2)
        return true;
    
    if(nums[cur] <= nums[cur + 2] || nums[cur - 1] <= nums[cur + 1])
        return true;
    
    return false;
}

/*
    Check adjecent elements and store the faulted position.
    Keep increasing the counter on fault.
    
Edge case: 
    [3,4,2,3] = False 
        Handeled at last.
*/


