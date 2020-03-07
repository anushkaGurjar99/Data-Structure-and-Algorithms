/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/daily-temperatures

class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        if(T.size() < 1)
            return result;
        stack<int> countDays;
        
        for(int i = 0; i < T.size() - 1; i++){
            if(T[i] < T[i+1]){
                result[i] = 1;
                if(!countDays.empty()){
                    while(T[countDays.top()] < T[i+1]){
                        result[countDays.top()] = i - countDays.top() + 1;
                        countDays.pop();
                        if(countDays.empty())
                            break;
                    }
                }
            }
            else{
                countDays.push(i);
            }
        }
        
        return result;
    }
};

/*
If curr+1 is greater than curr element, simple store 1 in result[i]
  loop{check curr+1 to top element of stack if it is having hotter temp (elements in stack are in incr order from top)
      if condition true then store the diff (i - top) in result[top]
      pop element from stack
      if stack empty then exit}
else
   push curr element into stack.
*/

