/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k){
        
        string str;
        for(int i = 1; i <= n; i++){
            char c = i + '0';
            str.push_back(c);
        }
        
        while(k-- > 1)
            getNextPermutation(str);
        
        return str;
    }
    
    void getNextPermutation(string& str){
        int i = str.size() - 2;
        
        for(; i >= 0; i--){
            if(str[i] < str[i + 1])
                break;
        }
        
        int j = i + 1;
        while(j < str.size() && str[i] < str[j])
            j++;
        
        swap(str[j - 1], str[i]);
        reverse(str.begin() + i + 1, str.end());
    }
    
};

/*
Simply we are generating ASC sorted order of nums and returning the Kth permutation.

OLE: when you change the comparision sequence (i, i + 1 into i, i - 1)
TLE: when you generate all permutations, sort them in ASC order and return the Kth sequence

Approach:
    SAME AS NEXT PERMUTATION.
*/




