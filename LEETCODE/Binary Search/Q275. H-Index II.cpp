/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/h-index-ii/

class Solution{
public:
    int hIndex(vector<int>& citations){
        
        if(citations.size() < 1)
            return 0;
                
        int size = citations.size();
        int left = 0;
        int right = size - 1;
        int res = 0;

        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(citations[mid] >= size - mid){
                res = size - mid;
                right = mid - 1;
            }
            else{
                left  = mid + 1;
            }         
        }
        
        return res;
    }
};

// ref: https://www.youtube.com/watch?v=CjKJDloMnwE&t=933s
