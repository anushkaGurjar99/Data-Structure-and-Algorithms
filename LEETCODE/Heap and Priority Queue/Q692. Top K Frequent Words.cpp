/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/top-k-frequent-words/

typedef pair<int, string> P;
class Solution{

private:
    struct comparator{
      bool operator()(const P& lhs, const P& rhs){
        if(lhs.first == rhs.first){
            // freq is same, lexographically greater first ( kinda max heap ) : opposite sign used
            return lhs.second < rhs.second;
        }
        // min heap : less freq first : opposite sign to be used
        return lhs.first > rhs.first;
    }
};
    
public:
    vector<string> topKFrequent(vector<string>& words, int k){
        
        unordered_map<string, int> m;
        for(auto word: words)
            m[word]++;
        
        priority_queue<P, vector<P>, comparator> pq;        // MIN heap
        for(auto itr: m){
            pq.push({itr.second, itr.first});
            if(pq.size() > k)
                pq.pop();
        }
        // case: [a, aa, aaa], k = 1 => output should be 'a' not 'aaa'
        
        vector<string> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
