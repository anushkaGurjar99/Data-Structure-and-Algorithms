/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(p.size() > s.size())
            return {};
        
        vector<int> p_count(26, 0);
        
        for (char c : p)
            p_count[c - 'a']++;
        
        vector<int> s_count(26, 0);
        
        vector<int> result;
        
        for (int i = 0; i + 1 < p.size(); i++)
            s_count[s[i] - 'a']++;
        
        for (int i = 0; i + p.size() <= s.size(); i++){
            char index = s[i + p.size() - 1];
            s_count[index - 'a']++;
            
            if (p_count == s_count)
                result.push_back(i);
            
            s_count[s[i] - 'a']--;
        }
        return result;
    }
};

// TIME LIMIT EXCEED
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
          
        vector<int> result;
        unordered_map<char, vector<int>> m;
        unordered_map<char, int> c;
         
        
        for(int i = 0; i < p.size(); i++)
            c[p[i]]++;
        
        
        unordered_map<char, int> save = c;
        int length = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            auto itr = c.find(s[i]);
            
            if(itr != c.end()){
                if(itr->second > 0){
                    length++;
                    c[s[i]]--;
                }
                
                m[s[i]].push_back(i);
                
                if(length == p.size()){
                    
                    int minn = INT_MAX; 
                    for(auto itr: m)
                        minn = min(minn, itr.second[itr.second.size() - save[itr.first]] );
                    
                    if(minn + p.size() - 1 == i)
                        result.push_back(minn);
                    
                    m.clear();
                    c = save;
                    length = 0;
                    i = minn;                       // search from this pos again
                }
            }
        }
        
        return result;
    }
};

/*
Take two hash:
  one for its frequence 
  second for the indexes where it has occured
  
as soon as we encountered all characters of demanded string, 
  we find the least recent occured element from indexes array

if the least recently occured elemnt + len of demanded string is == current char 
this mean that we have covered all the elements (so we push the least recently occured element in result array)
*/

