/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

int* sumZero(int n, int* returnSize){
    *returnSize = n;
    
    int* result = (int*) malloc(n * sizeof(int));
    int pos = 0;
    int num = 1;
    
    oddCase(&pos, result, &n);
    
    while(n != 0){
        result[pos] = num;
        result[pos + 1] = num * -1;
        num++;

        pos += 2;
        n -= 2;
    }
    
    return result;
}

void oddCase(int* pos, int* result, int* n){
    if(*n % 2 != 0){
        *n -= 1;
        result[*pos] = 0;
        *pos += 1;
    }
}

/*
    oddCase()
        *n-- or *pos++ won't work
        see the pass by reference syntax
        
    don't forget to initliaze returnSize.
*/
