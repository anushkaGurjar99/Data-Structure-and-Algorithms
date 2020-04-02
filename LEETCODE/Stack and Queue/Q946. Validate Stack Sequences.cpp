/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/validate-stack-sequences/

// Greedy Solution
class Solution{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        
        if(pushed.size() == 0)
            return true;
        
        stack<int> sequence;
        int i = 0;
        
        for(auto curr: pushed){
            sequence.push(curr);
            
            while(!sequence.empty() && sequence.top() == popped[i]){
                sequence.pop();
                i++;
            }
        }
        
        return sequence.empty();
    }
};

/*
Approch:
The element must be pushed before popping so we keep a pointer on 0th popped element (say i)

Traverse the pushed array
    Insert curr element in stack
    if the TOP element of stack is matched with popped[i]
        Then we pop the stack element and
        incr i to check whether next element also has to be popped or not

At last we will check the stack is empty or not
(empty if sequence matches else it will contain elements)

Space complexity: O(n)
Time complexity: O(n+m) = O(n)
*/
