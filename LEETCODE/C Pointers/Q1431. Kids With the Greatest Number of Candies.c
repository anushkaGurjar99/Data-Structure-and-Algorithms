/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : C
*/

// Problem Statement: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    
    bool* result = (bool*) malloc(candiesSize * sizeof(bool));
    *returnSize = candiesSize;

    int maxCandies = 0;
    
    for(int i = 0; i < candiesSize; i++)
        maxCandies = candies[i] > maxCandies ? candies[i] : maxCandies;
    
    for(int i = 0; i < candiesSize; i++)
        result[i] = (candies[i] + extraCandies >= maxCandies) ? true : false;
    
    return result;
}

