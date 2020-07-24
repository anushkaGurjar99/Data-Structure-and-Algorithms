/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/create-target-array-in-the-given-order/

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    
    *returnSize = numsSize;
    int* result = (int*) malloc(numsSize * sizeof(int));
    
    for(int i = 0; i < numsSize; i++){
        
        int pos = i;
        
        // free up the cell by shifting...
        while(pos > index[i]){
            result[pos] = result[pos - 1];
            pos--;
        }
        
        result[index[i]] = nums[i];
    }
    
    return result;
}
