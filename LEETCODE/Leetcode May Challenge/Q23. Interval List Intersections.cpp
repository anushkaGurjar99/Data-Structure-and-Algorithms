/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B){
        
        if(A.size() == 0 || B.size() == 0)
            return {};
        
        vector<vector<int>> result;
        
        for(int one = 0, two = 0; one < A.size() && two < B.size(); ){
            
            getIntersection(result, A[one], B[two]);
            
            if(A[one][1] < B[two][1])
                one++;
            else if(A[one][1] > B[two][1])
                two++;
            else
                one++, two++;
        }
        
        return result;
    }
    
    void getIntersection(vector<vector<int>>& result, vector<int> one, vector<int> two){
        
        if(one[0] <= two[0] && one[1] >= two[0])
            result.push_back({two[0], min(one[1], two[1])});
        
        else if(two[0] < one[0] && two[1] >= one[0])
            result.push_back({one[0], min(one[1], two[1])});
        
    }
    
};

/*
Intution:

Obervation - Both arrays are sorted and each array is set of non-overlaping intervals.

Pick first interval from each array (say 'one' and 'two' pointing the same)
    - get the intersection (if any)
    - if f(one) is less than f(two) -> increment one 
    - else if f(one) is greater than f(two) -> increment two
    - else increment both one and two
    
f(n): finishing time
s(n): starting time

How would you get intersection:
    case1: one has started earlier or at same time than two && f(one) is greater than or equal to s(two)
    case2: two has started earlier than one && f(two) is greater than or equal to s(one)
*/
