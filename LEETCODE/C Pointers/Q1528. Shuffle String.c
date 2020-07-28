/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/shuffle-string/



char* restoreString(char *s, int* indices, int indicesSize){
    
    char *result = (char*) malloc(indicesSize + 1 * sizeof(char));
    
    for(int i = 0; i < indicesSize; i++)
        result[indices[i]] = s[i];
    
    result[indicesSize] = '\0';
    
    return result;
}

// Note the null character.
