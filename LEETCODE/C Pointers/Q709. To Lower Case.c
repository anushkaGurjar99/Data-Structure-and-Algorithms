/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/to-lower-case/

char * toLowerCase(char * str){
    
    int size = strlen(str);
    
    for(int i = 0; i < size; i++){
        if(str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    }
    
    return str;
}

// a-z => {97, 122},     A-Z => {65, 90} 
