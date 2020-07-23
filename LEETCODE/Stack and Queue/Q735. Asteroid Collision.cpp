/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/asteroid-collision/

class Solution{
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        
        stack<int> s;
        for(auto i: asteroids){
            bool f = true;
            bool edge = false;
            
            while(!s.empty() && s.top() > 0 && i < 0 && !edge){
                f = false;
                if(s.top() > abs(i)) 
                    break;
                
                if(s.top() == abs(i))
                    edge = true;
                
                s.pop();
            }
            
            if(edge)
                continue;
            
            if(f || (!s.empty() && !(s.top() > 0 && i < 0)) || s.empty())
                s.push(i);
        }
        
        return getResult(s);
    }
    
    vector<int> getResult(stack<int>& s){
        vector<int> result(s.size());
        for(int j = s.size() - 1; j >= 0; j--){
            result[j] = s.top();
            s.pop();
        }
        return result;
    }
};

/*
Solution 1: stack
            space O(n), time O(2n) = O(n)
            at worst condition I have to remove all elements after insertion in stack.
            

Approach:
We check each Asteroid linearly that whether its a collision or not.

    :Collision happens only when Dir(top_of_stack) is right and Dir(curr) is left
        If Weight(top_of_stack) > Weight(curr)
            It will destroy curr, so we break here;

        Further, if both asteroids have same weight then both are miss 
            Hence we mark this edgeCase to handle it later and break from loop;
                    
        If above are not the case, then we can desroy top_of_stack.
        
    If edgeCase is marked 
        we continu, as no operation left on curr.
        
    When do we store curr into stack ?
    If (we never entered into loop) OR (Dir of top and i is same) OR (destroyed all asteroids from curr)
    
At last the elements left in Stack will be stored into result as leftover asteroids.
*/



