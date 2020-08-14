/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/lru-cache/

typedef pair<int, int> P;

class LRUCache{
private:
    int limit;
    int weight;
    unordered_map<int, int> m;
    unordered_map<int, int> freq;
    priority_queue<P, vector<P>, greater<P>> pq;
    
public:
    LRUCache(int capacity){
        limit = capacity;
        weight = 0;
    }
    
    int get(int key){
        if(m.find(key) == m.end())
            return -1;
        
        freq[key] = weight;
        pq.push({weight, key});
        weight++;
        
        return m[key];
    }
    
    void put(int key, int value){
        if(m.size() == limit && m.find(key) == m.end()){    // remove form map only if input key is new
            while(1){
                int w = pq.top().first;
                int k = pq.top().second;
                pq.pop();
                if(freq[k] == w){
                    m.erase(k);
                    freq.erase(k);
                    break;
                }
            }
        }
        
        freq[key] = weight;
        m[key] = value;
        pq.push({weight, key});
        weight++;
    }
};

/*

MAP1: To store the key-value pair
MAP2: To store the last-visit of a key
PQue: To store the visit-key pair 

In each get iteration:
    If KEY don't exist we return -1. 
    Else-
        we will update the MAP2
        we will update the PQue as last call for KEY has been changes
        and return the VALUE from MAP1
        
In each Put iteration:
    If does not exist AND MAP limit is full
        We find the pair
            where LAST call of a KEY in MAP2 is same is PQ TOP.first
            if current pair is not such pair, we pop it and do it again.
            
    We update MAP1, MAP2 and PQ.
    
_______________________________________________________________________________________________

Data MAP
    key: val
    1:  1
    2:  2
    
Freq MAP
    key: weight
    1:  0 -> 2
    2:  1
    
Sequence PQ
    freq: key
    0: 1
    1: 2
    2: 1
*/



