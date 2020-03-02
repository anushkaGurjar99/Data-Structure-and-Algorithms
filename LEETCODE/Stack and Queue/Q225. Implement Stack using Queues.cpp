/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
private:
    queue<int> que;

public:
    /** Initialize your data structure here. */
    MyStack(){
        
    }
    
    /** Push element x onto stack. */
    void push(int x){
        if(que.empty()){
            que.push(x);
        }
        else{
            queue<int> temp;
            temp.push(x);
            while(!que.empty()){
                temp.push(que.front());
                que.pop();
            }
            que = temp;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop(){
        int res = que.front();
        que.pop();
        return res;
    }
    
    /** Get the top element. */
    int top(){
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty(){
        if(que.empty())
            return true;
        return false;
    }
};
// push O(n), pop O(1), top O(1)

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


// ************************************* Approach : push O(1), pop O(n), top O(n) *************************************

class MyStack{
private:
    queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack(){
        
    }
    
    /** Push element x onto stack. */
    void push(int x){
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop(){
        queue<int> temp;
        while(que.size() > 1){
            temp.push(que.front());
            que.pop();
        }
        int res = que.front();
        
        que = temp;
        
        return res;
    }
    
    /** Get the top element. */
    int top(){
        
        queue<int> temp;
        while(que.size() > 1){
            temp.push(que.front());
            que.pop();
        }
        int res = que.front();
        
        temp.push(res);
        que = temp;
        
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty(){
        if(que.empty())
            return true;
        return false;
    }
};
