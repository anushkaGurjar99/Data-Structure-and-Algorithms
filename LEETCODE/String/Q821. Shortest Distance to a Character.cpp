/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/shortest-distance-to-a-character/

class Solution{
public:
    vector<int> shortestToChar(string S, char C){
        
        int size = S.size();
        stack<int> st;
        vector<int> result(size, size);
        int lastC = -1;
        
        for(int i = 0; i < size; i++){
            if(S[i] == C){
                result[i] = 0;
                while(!st.empty()){
                    int top = st.top();
                    st.pop();
                    result[top] = min(i - top, result[top]);
                }
                lastC = i;
            }
            else{
                st.push(i);
                if(lastC != -1)
                    result[i] = (i - lastC);
            }
        }
        
        return result;
    }
};

/*
App1: Linear scan for each char

App2: Stack
        case1:
            if curr char is C than, remove empty the stack by filling diff
            store the result[i] = 0
            mark the lastVisitiedC = i
            
        case2:
            curr char is not C
            if lastVisitedC is valid index
                store the diff into result array
*/

