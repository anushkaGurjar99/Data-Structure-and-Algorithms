/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/simplify-path

class Solution{
public:
    string simplifyPath(string path){
        string next;
        stack<string> res;
        
        for(int i = 0; i < path.size(); i++){ 
            next = "";
            
            
            while(true){
                next += path[i];
                if(path[i] == '/' || (i == path.size() - 1) ){
                    
                    if(next.size() > 1 && next[next.size() - 1] == '/')
                        next.pop_back();
                    
                    break;
                }
                i++;
            }
            
            if(next == ".."){
                if(!res.empty())
                    res.pop();
            }
            else if(next != "/" && next != "."){
                res.push(next);
            }
            else{}
            
        }
        
        next = "";
        while(!res.empty()){
            next = "/" + res.top() + next;
            res.pop();
        }
            
        return (next == "") ? "/" : next;
    }
};

/*
Store the token in Stack which will be part of path
pop elements from stack and insert at front with "/" 
*/
