/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/valid-parenthesis-string/

class Solution{
public:
    bool checkValidString(string s){
        
        int balance = 0;
        int maxOpen = 0;
        
        for(auto ch: s){
            
            balance = (ch == '(') ? ++balance : --balance;
            maxOpen = (ch != ')') ? ++maxOpen : --maxOpen;
            
            balance = max(0, balance);
            
            if(maxOpen < 0)
                return false;
        }
        return balance == 0;
    }
};

/*
Intuition:
One pass on the string S we need to know, how many ')' we are waiting for.

If we meet too many ')', we can return false directly.
If we wait for no ')' at the end, then we are good.


Explanation:
We count the number of ')' we are waiting for,
and it's equal to the number of open parenthesis.
This number will be in a range and we count it as [balance, maxOpen]

When you met "(", you know you need one only one ")", balance = 1 and maxOpen = 1.
When you met "(*(", you know you need one/two/three ")", balance = 1 and maxOpen = 3.

The string is valid for 2 condition:
maxOpen will never be negative., balance is 0 at the end.
*/
