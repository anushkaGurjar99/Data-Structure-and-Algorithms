/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/shuffle-an-array/

class Solution{
public:
    vector<int> save;
    vector<int> arr;
    
    Solution(vector<int>& nums){
        save = arr = nums;    
    }
    
    vector<int> reset(){
        return save;
    }
    
    vector<int> shuffle(){
        int size = arr.size();
        for(int i = 0; i < size; i++){
            int pos = rand() % size;
            swap(arr[pos], arr[i]);
        }
        return arr;
    }
};

// shuffling based on random selection of index, which gives the equal probability.
