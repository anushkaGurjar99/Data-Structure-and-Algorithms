/*
 * Author : Anushka Gurjar
 * Date   : MAY 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/letter-case-permutation/

// DFS
class Solution{
public:
    vector<string> letterCasePermutation(string S){
        vector<string> result;
        getPermutations(S, result, 0);
        return result;
    }
    
    void getPermutations(string S, vector<string>& result, int i){
        
        result.push_back(S);
        if(i >= S.size())
            return;
        
        for(int j = i; j < S.size(); j++){
            if(isalpha(S[j])){
                S[j] ^= 32;
                getPermutations(S, result, j + 1);
                S[j] ^= 32;
            }
        }
        
        return;
    }
};

/*
Revert current character
Store it into result and search for it's next characters
Restore original character

Ex:
string = "amr"

FLOW =>     amr
            Amr
            AMr
            AMR
            AmR
            aMr
            aMR
            amR
            
Toggle logic: 97(a) - 65(A) is equal to 32.
*/

// ************************************************* BFS ***********************************************************

class Solution{
public:
    vector<string> letterCasePermutation(string S){
        
        vector<string> result;
        queue<string> q;
        string levelMarker = " ";
        
        for(int i = 0; i < S.size(); i++){
            
            if(isalpha(S[i])){
                if(q.empty()){
                    q.push(S);
                    S[i] ^= 32;
                    q.push(S);
                    S[i] ^= 32;
                    q.push(levelMarker);
                }
                else{
                    while(q.front() != levelMarker){
                        string curr = q.front();  
                        q.push(curr);
                        curr[i] ^= 32;
                        q.push(curr);
                        q.pop();
                    }
                    q.pop();                            // pop levelMarker
                    q.push(levelMarker);
                }
            }
        }
        
        while(!q.empty()){
            if(q.front() != levelMarker)
                result.push_back(q.front());
            q.pop();
        }      
        if(result.size() == 0)
            result.push_back(S);
        
        return result;
    }
};

/*
BFS appraoch:

Image there is a binary tree, we start from the dummy root, and the left child node means choice
1(append a lower case), and right child node is choice 2(upper case). Hence if String here is
"ab", we have a tree looks like this.
                            
                         /     \
                        a       A
                       /  \    / \
                      ab  aB  Ab  AB

Obviously our goal here will be printing out all leaf nodes.
*/


