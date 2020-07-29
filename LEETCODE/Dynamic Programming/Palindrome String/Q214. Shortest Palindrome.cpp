/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/shortest-palindrome/

// TLE for one case.

class Solution{
public:
    string shortestPalindrome(string s){
        
        if(s.size() <= 1)
            return s;
        
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = true;

            for(int j = 0; j < i; j++){
                if(s[i] == s[j] && (i - j == 1 || dp[j + 1][i - 1]))
                    dp[j][i] = true;
            }
        }
        
        int longest = s.size();
        for(int i = dp[0].size() - 1; i >= 0; i--){
            if(dp[0][i] == true){
                longest = i + 1;
                break;
            }
        }
        
        string x = s.substr(longest);
        reverse(x.begin(), x.end());
        s = x + s;
        
        return s;
    }
};

/*
    Approach:
        store all the palindromes in DP array.
            (check border elements then check the inner string.) if size >= 3
            (check border elements.) if size == 2
            single char is always palindrome.
            
        at last check the 0th row, which denotes palindroms that starts with 0th char.
        store the last index of palindrome starting.
        
        store the substring in reverse order from last_index + 1 to size of string.
        
        
        dp[i][j] denotes: substring from i to j is palindrome or not
*/


// ************************************************************************************************************************************************
class Solution{
public:
    string shortestPalindrome(string s){
        
        string temp = s;
        int size = s.size();
        reverse(temp.begin(), temp.end());
        
        for(int i = 0; i < s.size(); i++){
            if(s.substr(0, size - i) == temp.substr(i))
                return temp.substr(0, i) + s;
        }
        
        return "";
    }
};

/*
Approach 2: reverse the string and store into s'
            check the longest palindrome in s' where substring begin from s[0] in s.

a a c e c a a a
a a a c e c a a

*/
