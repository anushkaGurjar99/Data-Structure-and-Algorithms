/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        if(list1.size() < 1 || list2.size() < 1)
            return {};
        
        unordered_map<string, int> m;
        vector<string> result;
        
        for(int i = 0; i < list1.size(); i++)
            m[list1[i]] = i;
        
        int min = INT_MAX;
        for(int i = 0; i < list2.size(); i++){
            if(m.find(list2[i]) != m.end()){
                
                int sum = i + m[list2[i]];
                if(sum < min){
                    result.clear();
                    result.push_back(list2[i]);
                    min = sum;
                }
                else if(sum == min){
                    result.push_back(list2[i]);
                }             
                
            }
        }
        
        return result;
    }
};
