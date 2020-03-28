/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        
        if(nums.size() < 1)
            return {};
        
        unordered_map<int, int> numCount;
        for(int i = 0; i < nums.size(); i++)
            numCount[nums[i]]++;
        
        vector<int> result;
        int maxFrequency = INT_MIN;
        unordered_map<int, vector<int>> m;
                                                       
        for(auto itr: numCount){                         // reversing the numCount
            int curr = itr.second;
            maxFrequency = max(maxFrequency, curr);
            m[curr].push_back(itr.first);
        }
        numCount.clear();
        
        while(k > 0){
            if(m.find(maxFrequency) != m.end()){
                for(auto num: m[maxFrequency]){
                    k--;
                    result.push_back(num);
                }
            }
            maxFrequency--;
        }                                              
        
        return result;
    }
};

/*
Approach:
Store frequency of each element of nums. (say F)

After gettting frequency we need to get the MAX K.
    To get MAX freq we reverse the frequency map(say R)

Check if the MAX freq exist in R till K > 0
    if it is then push its corrosponing values in result array
    and decrement k by <elements stored>.
    decrement MAX to check the next MAX;
*/
