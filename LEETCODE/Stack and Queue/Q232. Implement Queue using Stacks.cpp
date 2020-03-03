/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/implement-queue-using-stacks

// push: O(n), pop: O(1), front: O(n)

class MyQueue {
private:
    stack<int> result;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        
        while(!result.empty()){
            temp.push(result.top());
            result.pop();
        }
        result.push(x);
        while(!temp.empty()){
            result.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = result.top();
        result.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return result.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return result.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 
 /*
 RES is global stack
 PUSH :
 - push elements of RES in temp stack (reverse RES)
 - push 'x' into RES
 - push elements of temp into RES (original RES with 'x' as bottom most value)
 */
 
 
 // *********************************** Approach: push O(1), pop O(n), front O(n) *****************************************
 class MyQueue {
private:
    stack<int> result;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        result.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop(){
        int f = getFront(result, 1);
        return f;
    }
    
    /** Get the front element. */
    int peek() {
        int f = getFront(result, 0);
        return f;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return result.empty();
    }
    
    int getFront(stack<int>& res, bool remove){
        stack<int> temp;
        while(res.size() > 1){
            temp.push(res.top());
            res.pop();
        }
        int front = result.top();
        result.pop();
        
        if(!remove)
            temp.push(front);
        
        while(!temp.empty()){
            res.push(temp.top());
            temp.pop();
        }
        return front;
    }
};

/*
 RES is global stack
 FRONT/ POP :
- push elements of RES in temp stack till size > 1 (reverse RES)
- store RES.top() into front and call RES.pop() which make the RES empty()
- if remove==false, push front into temp
- push elements of temp in RES stack (origianl RES, in case of POP it will remove the last element)
 */
