/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder{
private:
    priority_queue<double, vector<double>, greater<double>> right;
    priority_queue<double> left;
        
public:
    MedianFinder(){}
    
    void addNum(int num){
        
        int lSize = left.size();
        int rSize = right.size();
        
        if(lSize == 0){
            left.push(num);
        }
        
        else if(lSize == rSize){
            if(right.top() >= num){
                left.push(num);
            }
            else{
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }
        
        else if(left.top() <= num){
            right.push(num);
        }
        
        else{
            right.push(left.top());
            left.pop();
            left.push(num);
        }
    }
    
    double findMedian(){
        int size = left.size() + right.size();
        double res = (size % 2 == 0) ? (left.top() + right.top()) / 2 : left.top();
        return res;
    }
};

/*
Appraoch:
    divide stream into two parts where,
    all elements of Left range are smaller than all elements of Right range.
    
    Left range:     MAX heap
    Right range:    MIN heap

find median cases
    Even case: LR.size() == RR.size()
    Odd case : LR.size() + 1 == RR.size()

Add number cases - 
    case1:
        Left range is empty, so we push at left side
        
    case2:
        Length of Left range == Length of Right range
            If num is less than or equals to right.top()
                we push it into left range
            else
                we push one element to right range into left range, pop it from right
                push num into right range
                
    case3:
        (Length of left range is greater than Right range)
        If left.top() is smaller or equals to the num
            we push number into right range
            
    case4:
        else of case 3
        push left.top() into right range, pop it from left 
        push num into left

*/

// **********************************************************************************************************************************************************

class MedianFinder {
private:

    // max heap by default
    priority_queue<int, vector<int>, less<int>> leftHalf;

    // min heap
    priority_queue<int, vector<int>, greater<int>> rightHalf;

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {

        // edge case
        if(leftHalf.empty()){
            leftHalf.push(num);
            return;
        }

        // lefthalf has size n+1 and rightHalf has size n
        if(leftHalf.size() > rightHalf.size()){
            if(num > leftHalf.top()){
                rightHalf.push(num);
            }
            else{
                rightHalf.push(leftHalf.top());
                leftHalf.pop();
                leftHalf.push(num);
            }
        }
        // lefthalf has size n and rightHalf has size n+1
        else if(rightHalf.size() > leftHalf.size()){
            if(num > rightHalf.top()){
                leftHalf.push(rightHalf.top());
                rightHalf.pop();
                rightHalf.push(num);
            }
            else{
                leftHalf.push(num);
            }
        }
        
        // lefthalf and rightHalf have equal elements
        else{
            if(num > ((leftHalf.top() + rightHalf.top())/2.0))
               rightHalf.push(num);
            else
                leftHalf.push(num);
        }
    }

    double findMedian(){

        // median is the root of the larger heap
        if(leftHalf.size() == rightHalf.size())
            return ((leftHalf.top() + rightHalf.top())/2.0);

        if(leftHalf.size() > rightHalf.size())
            return leftHalf.top();

        return rightHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
