/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        
        if(nums.size() < 1)
            return 0;
        
        unordered_map<int, int> m;
        
        int cf = 0;
        m[cf] = 1;
        
        int result = 0;

        for(int i = 0; i < nums.size(); i++){
            
            cf += nums[i];
            
            if(m.find(cf - k) != m.end())
                result += m[cf - k];  
            
            m[cf]++;          // this generates (add before/after search) different result
        }
            
        return result;
    }
};


// line 33 elaboration: https://leetcode.com/submissions/detail/316695902/
