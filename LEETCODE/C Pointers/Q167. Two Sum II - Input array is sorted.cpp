/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/


int* twoSum(int* nums, int size, int target, int* returnSize){

    *returnSize = 2;
    int* result = (int*) malloc(2 * sizeof(int));
    result[0] = result[1] = 0;
    
    int left = 0;
    int right = getRightIndex(nums, size, target);
    right = (right == size) ? right - 1 : right;
    
    while(left < right){
        int pairSum = nums[left] + nums[right];
        if(pairSum == target)
            break;
        
        (pairSum < target) ? ++left : --right;
    }
    
    result[0] = 1 + left;
    result[1] = 1 + right;
    
    return result;
}

int getRightIndex(int* nums, int size, int target){
    
    int l = 0;
    int r = size - 1;
    int result = r;
    
    while(l < r){
        
        int mid = l + (r - l) / 2;
        
        if(nums[mid] <= target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    
    return l + 1;
}

/*
Appraoch:
    find the element which is just greater than target using BS.
    (-3, 3, 5),   target = 0
    
    then apply 2 pointers to find the pair.
*/
