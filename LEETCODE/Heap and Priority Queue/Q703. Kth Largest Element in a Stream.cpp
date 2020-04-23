/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest{
private:
    int limit;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums){
        limit = k;
        for(auto n: nums){
            if(pq.size() < limit){
                pq.push(n);
            }
            else if(pq.top() < n){
                pq.pop();
                pq.push(n);
            }
        }
    }
    
    int add(int val){
        pq.push(val);
        if(pq.size() > limit)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
 
