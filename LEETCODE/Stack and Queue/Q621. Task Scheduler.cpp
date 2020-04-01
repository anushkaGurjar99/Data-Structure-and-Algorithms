/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/task-scheduler/submissions/

class Solution{
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        if(n == 0 || tasks.size() < 2)
            return tasks.size();
        
        int size = 0;
        unordered_map<char, short> mapp;
        
        for(auto task: tasks)
            mapp[task]++;
        
        priority_queue <pair<short, char>> order;
        
        for(auto itr: mapp)
            order.push({itr.second, itr.first});
        
        pair<short, char> curr = order.top();                       
        order.pop();
        
        size = curr.first + ((curr.first - 1) * n);                   // fill the gap in advance
        
        while(!order.empty() && order.top().first == curr.first){    // if same freq exist
            ++size;
            order.pop();
        }        
        return size > tasks.size() ? size : tasks.size();               // edge case(1)                 
    }
};
// explanation -> https://leetcode.com/problems/task-scheduler/discuss/370755/C%2B%2B-solution-95-time-and-space-with-good-explanation


// ************************** Another approach which makes more sense but not optimal **************************

class Solution{
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        if(n == 0 || tasks.size() < 2)
            return tasks.size();
        
        unordered_map<char, short> mapp;
        
        for(auto task: tasks)
            mapp[task]++;
        
        priority_queue <pair<short, char>> order;
        queue <pair<short, char>> temp;                     // temporarily store top n elements of PQ
        int size = 0; 
        
        for(auto itr: mapp)
            order.push({itr.second, itr.first});            // store freq with char in PQ
        
        while(!order.empty()){
            
            setTopElement(order, temp);                     // save top element at size position
            size++;
            
            int i = 0;
            for(; i < n && !order.empty(); i++){  
                setTopElement(order, temp);
                size++;
            }
            
            if(i != n && !temp.empty())
                size += (n - i);
            
            while(!temp.empty()){
                order.push(temp.front());
                temp.pop();
            }
        }
        
        return size;
    }
    
    void setTopElement(priority_queue <pair<short, char>>& order, queue <pair<short, char>>& temp){
        pair <short, char> curr = order.top();
        curr.first--;
        if(curr.first > 0)
            temp.push(curr);
        order.pop();
    }
    
};


// space complexity: O(1), we are only storing at most 26 elements in PQ and n (n <= 26) elements in Q
// time complexity: O(n)

/*
Intution:
    Fill the MFT at first position then fill the n other MFT
    Now when you have filled n other tasks, you can refill the top MFT again 
    Repeat the process till all tasks has been filled.
*/
