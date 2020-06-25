/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

typedef pair<int, int> P;
class Solution{
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k){
        
        if(k == arr.size())
            return 0;
        
        unordered_map<int, int> m;
        for(auto num: arr)
            m[num]++;
        
        priority_queue<P, vector<P>, greater<P>> pq;
        
        for(auto itr: m)
            pq.push({itr.second, itr.first});
        
        while(k--){
            P curr = pq.top();
            pq.pop();
            if(curr.first != 1)
                pq.push({curr.first - 1, curr.second});
        }
        
        return pq.size();
    }
};

/*
Appraoch: Min Heap
(Remove the least freq elements first)

Note: A number will be discarded form array only when its freq is 0.

Store frequency of all elements in PQ.
Pop out the least frequent number and update the result.
    If freq is 1    -> number is completly gone
    If freq is > 1  -> number has to be restored with freq - 1 count.
*/
