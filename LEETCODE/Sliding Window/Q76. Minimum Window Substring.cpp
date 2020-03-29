/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-window-substring/

class Solution{
public:
    string minWindow(string s, string t) {
        vector<int> hist(128, 0);
        
        for(char c : t) 
            hist[c]++;

        int remaining = t.length();
        
        int left = 0;
        int right = 0;
        int minStart = 0;
        int minLen = INT_MAX;
        
        while(right < s.length()){
            hist[s[right]]--;
            if(hist[s[right]] >= 0) 
                remaining--;

            right++;
            
            while(remaining == 0){
                
                if(right - left < minLen){
                    minLen = right - left;
                    minStart = left;
                }
                
                hist[s[left]]++;
                if(hist[s[left]] > 0) 
                    remaining++;
                
                left++;
            }
        }

        return minLen < INT_MAX ? s.substr(minStart, minLen) : "";
    }
};

/*
Recommendation: Dry run this

Summary:

{decrement the count of resepected char in S, as soon as all char of T are found calculate lenght.
Then increment the count of char that were decremented before if any char found which is from T
                                                          search for that char in next iteration}
                                                          
*/
