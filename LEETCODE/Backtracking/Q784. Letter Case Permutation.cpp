/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/letter-case-permutation/

class Solution{
public:
    vector<string> letterCasePermutation(string S){
        vector<string> result;
        getPermutations(S, result, 0);
        return result;
    }
    
    void getPermutations(string S, vector<string>& result, int i){
        
        result.push_back(S);
        if(i >= S.size())
            return;
        
        for(int j = i; j < S.size(); j++){
            if(isalpha(S[j])){
                S[j] ^= 32;
                getPermutations(S, result, j + 1);
                S[j] ^= 32;
            }
        }
        
        return;
    }
};

/*
Revert current character
Store it into result and search for it's next characters
Restore original character

Ex:
string = "amr"

FLOW =>     amr
            Amr
            AMr
            AMR
            AmR
            aMr
            aMR
            amR
*/

