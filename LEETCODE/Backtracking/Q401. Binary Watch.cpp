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
    void backtrack(string& s, int start, int limit, vector<string>& res){

        int hours = std::bitset<4>(s.substr(6, 4)).to_ulong();
        if(hours > 11)
            return;

        int minutes = std::bitset<6>(s.substr(0, 6)).to_ulong();
        if(minutes > 59)
            return;

        if(limit == 0){
            string time = to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
            res.push_back(time);
            return;
        }

        if(start == s.length())
            return;

        for(int i = start; i < s.length(); i++){
            s[i] = '1';
            backtrack(s, i+1, limit-1, res);
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


/*
std::bitset<4>(s.substr(6, 4)).to_ulong();          // to_ulong converts given string into ulong

string "s" denotes the number of active bits
    first 6 bits are seconds and rem 4 bits are hour (this we will obtain using bitset)
    
make pairs of hour and minutes and check validity.
*/

// ***********************************************************************************************************************

class Solution {
public:
    vector<string> readBinaryWatch(int num){
        
        vector<string> result;
        
        for(int h = 0; h < 12; h++){
            for(int m = 0; m < 60; m++){
                
                int activeBits = __builtin_popcount(h) + __builtin_popcount(m);
                if(activeBits == num){
                    string t =  to_string(h) + ":" + (m > 9 ? "" : "0") + to_string(m);
                    result.push_back(t);
                }
            }
        }      
        return result;
    }
};

// check if number of setbits in both Hour and Min are equal to num.
