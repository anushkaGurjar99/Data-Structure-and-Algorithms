/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution{
private:
    struct comparator{
        bool operator()(const vector<int>& one, const vector<int>& two){
            return one[1] < two[1];
        }    
    }comp;
    
public:
    int findLongestChain(vector<vector<int>>& pairs){
        
        sort(pairs.begin(), pairs.end(), comp);
        
        int result = 0;
        int localMax = 0;
        int least = 0;
        
        for(int i = 0; i < pairs.size(); i++){
            if(localMax == 0 || least < pairs[i][0]){
                localMax++;            
                least = pairs[i][1];
            }
            result = max(localMax, result);
        }
        
        return result;
    }
};

/*
    1   20
    30  31
    2   300
    
    2   3
    5   9
    10  11
    1   20
        
    0   1
    3   4
    1   7
    6   8
    
    1   2
    2   3
    3   4
    
Sort based on Second node, check the longest using just a variable.

Greedy Appraoch:
    we know finishing time of each interval
    so we sort them based on finishing time.
    
    ________                                        J1
      ______________                                J2
                       ________                     J3
                                 _______            J4
                        ___________________         J5
                        
    now we take the first job, remove all its conflicts then pick up the next one.
    (J1, J3, J4 will be selected)
*/


