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
        bool operator()(const P& one, const P& two){
            if(one.first == two.first)
                return one.second < two.second;
            return one.first > two.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k){
        
        vector<string> result;
        unordered_map<string, int> m;
        fillMap(m, words);
        
        priority_queue<P, vector<P>, comparator> pq;
        fillPQ(m, pq, k);
        
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    void fillMap(unordered_map<string, int>& m, vector<string>& words){
        for(auto word: words)
            m[word]++;
    }
    
    void fillPQ(unordered_map<string, int>& m, priority_queue<P, vector<P>, comparator>& pq, int k){
        for(auto itr: m){
            pq.push({itr.second, itr.first});
            if(pq.size() > k)
                pq.pop();   
        }
    }
};

/*
    We know that String supports bool operations such has < > == and so on..
    
    step1:  calculate word frequencies
    step2:  create a min Heap, store K strings into heap that has HIGHEST frequency.  (that means if PQ size will exceed the K -> we will pop the least Freq element.
            If any collisions occurs in frequency, then check lexographic order.
    step3:  store the PQ elements into result
    step4:  reverse the result array since it was MIN heap so it would have returned incr order of freq.
*/



