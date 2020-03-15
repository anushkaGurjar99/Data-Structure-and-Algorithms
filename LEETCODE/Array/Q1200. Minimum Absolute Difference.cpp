/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-absolute-difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
         
        vector<vector<int>> result;
        
        sort(arr.begin(), arr.end(), greater<int>());
        
        int minDifference = arr[0] - arr[1];
        
        for(int i = arr.size() - 1; i > 0; i--)
            minDifference = min(arr[i-1] - arr[i], minDifference );
          
        for(int i = arr.size() - 1; i > 0; i--){
            if((arr[i-1] - arr[i]) == minDifference)
                result.push_back({arr[i], arr[i-1]});
        }
        
        return result;
    }
};

/*
Sort the numbers in increasing order

The minimum absolute difference will be found for only the adjacent pairs (all elements are distinct as mentioned in the question). 
Hence in one pass we calculate the minimum difference and in second pass we just push the elements having the minimum distance in the 
final answer array.
*/
