/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/binary-watch/

class Solution{
public:
    void backtrack(string& s, int start, int num, vector<string>& res){

        int hours = std::bitset<4>(s.substr(6, 4)).to_ulong();
        if(hours > 11)
            return;

        int minutes = std::bitset<6>(s.substr(0, 6)).to_ulong();
        if(minutes > 59)
            return;

        if(num==0){
            res.push_back(to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes));
            return;
        }

        if(start == s.length())
            return;

        for(int i=start; i<s.length(); ++i){
            s[i] = '1';
            backtrack(s, i+1, num-1, res);
            s[i] = '0';
        }
    }
    vector<string> readBinaryWatch(int num){
        vector<string> res;
        string s = "0000000000";                        // 4 + 6                    
        backtrack(s, 0, num, res);
        return res;
    }
};
