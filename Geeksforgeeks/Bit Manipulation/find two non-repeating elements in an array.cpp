/*
 * Author : Anuska Gurjar
 * Date   : Februaruy 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

void getTwoSoloElements(int arr[], int size, int &x, int &y){ 
    int result = arr[0];
    int firstSetBit; 
    int i;
    
    for(i = 1; i < size; i++)  
        result ^= arr[i];  
      
    firstSetBit = result & ~(result-1);  
      
    for(i = 0; i < size; i++){  
        if(arr[i] & firstSetBit)  
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }  
}  

// x = y = 0;
// function call : getTwoSoloElements(arr, size, x, y);
