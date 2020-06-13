/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/decode-string/

class Solution{
public:
    string decodeString(string s){
        int pos = 0;
        return helper(pos, s);
    }
    
    string helper(int& pos, string s){
        int num = 0;
        string word = "";
        
        for( ; pos < s.size(); pos++){
            char cur = s[pos];
            
            if(cur == '['){
                string curStr = helper(++pos, s);
                for( ; num > 0; num--) 
                    word += curStr;
            } 
            else if(cur >= '0' && cur <='9')
                num = num*10 + cur - '0';
            else if(cur == ']')
                return word;
            else
                word += cur;
            
        }
        return word;
    }
};

/*
Every time we meet a '[', we treat it as a subP so call our recursive function to get the content in that '[' and ']'. After that, repeat that content for 'num' times.

Every time we meet a ']', we know a subP finished and just return the 'word' we got in this subP.

Notice that the 'pos' is passed by reference, use it to record the position of the original string.
*/
