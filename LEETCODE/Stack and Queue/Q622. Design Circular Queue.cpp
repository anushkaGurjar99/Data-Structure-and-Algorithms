/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public:
    vector<int> q;
    int size;
    int head = -1;
    int tail = -1;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        q.resize(size);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }

        if(isEmpty()){
            head = tail = 0;
        }
        else{
            tail = (tail+1)%size;
        }
        q[tail] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if(head==tail){
            head = tail = -1;
        }
        else{
            head = (head+1)%size;
        }
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()){
           return -1;
        }
        return q[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()){
           return -1;
        }
        return q[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return tail==-1;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ( (tail - head + 1) % size == 0);
    }
};
