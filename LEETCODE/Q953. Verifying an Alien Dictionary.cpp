/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution{
public:
    bool isAlienSorted(vector<string>& words, string order){
        
        vector<int> seq(26);
        
        for(int i = 0; i < order.size(); i++)
            seq[order[i] - 'a'] = i;
        
        for(int i = 0; i < words.size() - 1; i++){
            string one = words[i];
            string two = words[i + 1];
            int limit = min(one.size(), two.size()) - 1;
            
            for(int j = 0; j <= limit; j++){
                if(seq[one[j] - 'a'] < seq[two[j] - 'a'])
                    break;
                if(seq[one[j] - 'a'] > seq[two[j] - 'a'])
                    return false;
                else if(j == limit && one.size() > two.size())
                    return false;
            }
        }
        
        return true;
    }
};

/*
Generate the char sequence according to given order.
Check if all words are sorted or not -
    a <= b <= c <= d        (a is automatically <= c and <= d)
    so need of extra comparisions.
    Just check the adjecent.
    
        If one[j] < two[j] 
            that means position is sorted and we can break.
        Else one[j] > two[j]
            umm..this is invalid
        Else if we are comparing last char and one.size() > two.size()
            this is also not valid
____________________________________________________________________________________________

Example: 
    "hello", "leetcode"
    order = "hlabcdefgijkmnopqrstuvwxyz"

Since "h" is before "l" in "order", the rest of letters need not to be compared.
Think about dictionary, "apple" is before "bee" even if "p" is after "e" in alphabet order

*/

