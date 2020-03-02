/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/min-stack

class MinStack {
private:
    stack<int> original;
    stack<int> min;
    
public:
    MinStack(){
    }
    
    void push(int x){
        original.push(x);
        if(min.empty() || x <= min.top())
            min.push(x);
    }
    
    void pop(){
        if(original.empty())
            return;
        if(original.top() == min.top())
            min.pop();
        original.pop();
    }
    
    int top(){
        if(original.empty())
            return 0;
        return original.top();
    }
    
    int getMin(){
        if(min.empty())
            return 0;
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
