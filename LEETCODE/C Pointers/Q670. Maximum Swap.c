/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/maximum-swap/

int maximumSwap(int num){
    
    int len = getLength(num);
    char arr[len];
    storeNum(arr, len, num);

    int pos = sortBreaker(arr, len);
    if(pos == -1)
        return num;
    
    int from = getLargest(pos + 1, arr, len);               // scan pos to n
    int to = getReplacePos(from, pos, arr);                 // scan pos to 0

    char ch = arr[from];
    arr[from] = arr[to];
    arr[to] = ch;
    
    num = 0;
    for(int i = 0; i < len; i++){
        num *= 10;
        num += (arr[i] - '0');
    }
    
    return num;
}

int getLength(int num){
    int len = 0;
    while(num > 0){
        len++;
        num /= 10;
    }
    return len;
}

void storeNum(char *arr, int len, int num){
    for(int i = len - 1; i >= 0; i--){
        arr[i] = '0' + (num % 10);
        num /= 10;
    }
}

int sortBreaker(char *s, int len){
    for(int i = 0; i < len - 1; i++){
        if(s[i] < s[i + 1])
            return i;
    }
        
    return -1;
}

int getLargest(int start, char* str, int len){
    for(int i = start; i < len; i++){
        if(str[i] >= str[start])                        
            start = i;
    }
    return start;
}
    
int getReplacePos(int from, int start, char* str){
    int result = start;
    for(int i = start; i >= 0; i--){
        if(str[i] < str[from])                            
            result = i;
    }        
    return result;
}

/*
Remember:
    Passing char array to a function

Rest is same as C++ check the apprach in Array/ folder.
*/

