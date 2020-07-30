/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-happy-string/

class Solution {
public:
    string longestDiverseString(int a, int b, int c){
        
        priority_queue<pair<int,string>> pq;
        string result = "";
        
        if(a) pq.push({a, "a"});
        if(b) pq.push({b, "b"});
        if(c) pq.push({c, "c"});
        
        
        while(pq.size() > 1){
            
            pair<int, string> one = pq.top();
            pq.pop();
            pair<int, string> two = pq.top();
            pq.pop();
            
            caseOne(one, result);
            caseTwo(one, two, result);
            
            if(one.first > 0) pq.push(one);
            if(two.first > 0) pq.push(two);
        }
        
        if(!pq.empty())
            addLeftover(pq, result);
        
        return result;        
    }
    
    void caseOne(pair<int, string>& one, string& result){
        if(one.first >= 2){
            result += one.second + one.second;
            one.first -= 2;
        }
        else{
            result += one.second;
            one.first -= 1;
        }
    }
    
    void caseTwo(pair<int, string>& one, pair<int, string>& two, string& result){
        if(two.first >= 2 && two.first >= one.first){
            result += two.second + two.second;
            two.first -= 2;
        }
        else{
            result += two.second;
            two.first -= 1;
        }
    }
    
    void addLeftover(priority_queue<pair<int,string>>& pq, string& result){
        result += (pq.top().first >= 2) ? (pq.top().second + pq.top().second) : (pq.top().second);
    }
};


/*
Create a max heap of the form pair<int,char> to store the count of each character.

while (pq.size() > 1)
    Pop out the first 2 pair who have the max frequency.

Add greedily the occurances of the first pair to the ans and update it's count.

For the second pair, compare it's occurances with the first pair and add accordingly.

Finally add the pairs to the Max Heap if their count > 0.

If !pq.empty() add the leftover character to the ans according to the remaining counts and return the ans.
*/
