/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/sort-array-by-parity/

int* sortArrayByParity(int* A, int ASize, int* returnSize){
    
    *returnSize = ASize;
    
    int *result = (int*) malloc (ASize * sizeof(int));
    int pos = 0;
    
    for(int i = 0; i < ASize; i++){
        if(A[i] % 2 == 0)
            result[pos++] = A[i];
    }
    
    for(int i = 0; i < ASize; i++){
        if(A[i] % 2 != 0)
            result[pos++] = A[i];
    }
    
    return result;
}

/* TWO PASS APPROACH */


// ***********************************************************************************************************************

int* sortArrayByParity(int* A, int ASize, int* returnSize){
    
    *returnSize = ASize;
    int even = 0;
    
    for(int i = 0; i < ASize; i++){
        if(A[i] % 2 == 0){
            int x = A[i];
            A[i] = A[even];
            A[even] = x;
            even++;
        }
    }
    
    return A;
}

/* 
Since order of elements does not matter, we can use two pointer approach.
*/
