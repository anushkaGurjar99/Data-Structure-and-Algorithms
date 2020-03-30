/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution{
public:
    int subarraysDivByK(vector<int>& A, int K){
        
        int result = 0;
        
        if(A.size() < 1)
            return result;
        
        unordered_map<short, int> count;
        
        int cf = 0;
        count[cf]++;
        
        for(int i = 0; i < A.size(); i++){ 
            cf += A[i];
            int rem;
            
            
            // C++ don't supper MOD operation on -ve so we have to write manually 
            if(cf >= 0){
                rem = cf % K;
            }            
            else{
                rem = K - (abs(cf) % K);
                if(rem == K)
                    rem = 0;
            }
            
            auto itr = count.find(rem);
            
            if(itr != count.end())
                result += itr->second;
            
            count[rem]++;
        }
        
        return result;
    }
};

/*
Add the cumulative frequency in each iteration and keep adding it's hash value to result which
denotes how many combination with this current value we can create.
*/
