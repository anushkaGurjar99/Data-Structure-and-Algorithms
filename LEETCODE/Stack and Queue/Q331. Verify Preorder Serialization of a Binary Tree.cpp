/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution{
public:
    bool isValidSerialization(string preorder){
        if(preorder.size() < 1)
            return false;
        
        vector<string> nodes = getNodes(preorder);
        if(nodes[0] == "#")
            return (nodes.size() == 1);
      
        stack<pair<bool, bool>> st;
        st.push({false, false});
        
        for(auto node: nodes){
            if(st.empty())
                return false;
            
            (!st.top().first) ? st.top().first = true : st.top().second = true;
            
            if(node != "#")
                st.push({false, false});
    
            removeVisited(st);
        }
        
        return st.empty();
    }
    
    vector<string> getNodes(string& p){
        vector<string> nodes;
        string s;
        
        for(auto ch: p){
            if(ch == ','){
                if(s != "")
                    nodes.push_back(s);
                s = "";
                continue;
            }
            (ch == '#') ? nodes.push_back("#") : s.push_back(ch);
        }
        if(s != "")
            nodes.push_back(s);
        
        return nodes;
    }
    
    void removeVisited(stack<pair<bool, bool>>& st){
        while(!st.empty() && st.top().first == true && st.top().second == true)
                st.pop();
    }
};

/*
    create a stack with 2 bool var left and right
    if next element is found -> mark left true if left is false
                                else mark right true
    in each iteration pop those element having right and left as true
*/

