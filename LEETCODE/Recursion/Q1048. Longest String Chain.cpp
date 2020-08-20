/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-string-chain/

class Solution{
public:
    int longestStrChain(vector<string>& words){
        
        unordered_map<int, vector<string>> m;
        
        int minLen = INT_MAX;
        int maxLen = INT_MIN;
        for(auto itr: words){
            int l = itr.size();
            minLen = min(minLen, l);
            maxLen = max(maxLen, l);
            m[l].push_back(itr);
        }
        
        int result = 0;
        
        for(int i = minLen; i <= maxLen; i++)
            dfs(m, result, i, 0, "");
        
        return result;
    }
    
    void dfs(unordered_map<int, vector<string>>& m, int& result, int len, int ct, string s){
        
        result = max(result, ct);
        
        if(m[len].empty())
            return;
        
        for(auto itr: m[len]){
            if(s == "" || XOR(s, itr))
                dfs(m, result, len + 1, ct + 1, itr);
        }
    }
    
    bool XOR(string& one, string& two){
        int count = 0;
        for(int i = 0, j = 0; i < one.size(); i++, j++){
            if(one[i] != two[j]){
                count++;
                i--;
            }
            if(count == 2)
                return false;
        }
        return true;
    }
};

/*
Note: chain can start from any length, so we form chain for each length and update the result.

XOR(a, b), is true when a is predecessor of two.

Appraoch(DFS):
    get minLength and maxRange of string array.
    run a loop from minLen to maLen to find the max chain at each length.

*/

