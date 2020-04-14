/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s){
        
        string result;
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mapp;
        
        for(auto ch: s)
            mapp[ch]++;
        
        for(auto i: mapp)
            pq.push({i.second, i.first});
        
        while(!pq.empty()){
            pair<int, char> curr = pq.top();
            pq.pop();
            
            while(curr.first-- > 0)
                result.push_back(curr.second);
        }
        
        return result;
    }
};

/*
Approach:
    Count the frequency of all characters in 's'
    Store all the characters with frequency in Priority Queue
    Keep popping PQ till is is not emepty & store the top element in string (frequency times)
*/
