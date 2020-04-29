/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/531/week-4/3313/

/*
Since we are not popping out from queue so here's the points to be noted - 
  once an element gets more than one occurance -> it will run out of Unique number race for-ever
  every push may change the first unique
*/

class FirstUnique{
    list<int> unique;
    unordered_set<int> visited;
    unordered_set<int> repeated;
public:
    FirstUnique(vector<int>& nums){
        for(auto n: nums)
            helper(n);
    }
    
    int showFirstUnique(){
        while(!unique.empty()){
            int u = unique.front();
            if(repeated.find(u) == repeated.end())
                break;
            unique.pop_front();
        }
        return unique.empty() ? -1: unique.front();
    }
    
    void add(int value){
        helper(value);
    }    
    
    void helper(int n){
        if(visited.find(n) == visited.end()){
            visited.insert(n);
            unique.push_back(n);
        }
        else{
            repeated.insert(n);
        }
    }
};
/*
Approach:
  DS used:  A list for sequential record of unique num, 
            A visited set contains at least ones visited nums, 
            A repeated set contains the num having more than one occurance.
            
To push a number:
  check if number already exist in Visited
    If yes: push number into Repeated
    Else  : push number into Visited and Back to Unique
  
To pop a number:
  if Unique's front found in Repeated set
    pop Unique's front and repeat till above condition is True
  return the Unique's front (if exist, else -1)
*/

/*
Another Appraoch:
  DS used: Greater PQ <i, num> and Unordered_map <num, i>
  And a variable Last Unique (contains last unique found), and an index varible 
  
Push:
  store each element in PQ with index and value
  store each element in MAP (if element already exist then value = -1 else value = i)
  
Pop:
  check MAP[Last] into map
    return if i != -1
  pop PQ top,
    if MAP[top.num] != -1  (save it in Last and return Last)
    else  POP from PQ and repeat till cond true
*/
