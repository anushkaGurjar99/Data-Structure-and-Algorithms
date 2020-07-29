/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/rotate-string/

bool rotateString(char * A, char * B){
    
    int sizeA = strlen(A);
    int sizeB = strlen(B);
    
    if(sizeA != sizeB)
        return false;
    
    if(sizeA == 0)
        return true;
    
    for(int i = 0; i < sizeA; i++){
        
        char ch = A[0];
        for(int j = 0; j < sizeA - 1; j++)
            A[j] = A[j + 1];
        
        A[sizeA - 1] = ch;
        
        if(strcmp(A, B) == 0)
            return true;
    }
    
    return false;
}

/*
  remeber the functions strcmp and strlen.
  approach: check all the rotation with B, if any rotation is matched -> return true 
            if B is not one of all possible rotations of A -> return false
*/
