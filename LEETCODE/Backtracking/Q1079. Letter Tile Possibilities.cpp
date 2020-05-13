/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/letter-tile-possibilities/

class Solution {
public:
  
    void backtrack(unordered_map<char, int>& m, int& count){
        for(auto& it : m){
            if(it.second > 0){
                count++;
                it.second--;
                backtrack(m, count);
                it.second++;
            }
        }
    }
    
    int numTilePossibilities(string tiles){
        unordered_map<char, int> m;
        for(auto ch : tiles)
            m[ch]++;
    
        int count = 0;
        backtrack(m, count);
        return count;
    }
};

/*
Here we require the count of all possible permutations of a combination. 
So the idea is to use map to store the count of each letter in the string.

Then iterate over the key value pairs and for each key in the map 
    if it's value is greater than zero we increment the sum decrement the value . 
        Then we recursively find the combinations of the remaining string and add it to to our sum. 
        After that branch of recursion completes we restore the value (or count) of that key.
        
EX: "AAB"               
    
                                AAB
                               /   \
                            AB      AA
                          /   \      \
                         A     B      A
                         \     \      \ 
                         
*/

// ************************************************************************************************************************

class Solution {
public:
    int numTilePossibilities(string tiles){
        int result = 0;
        sort(tiles.begin(), tiles.end());
        backtrack(tiles, {}, result, 0);
        return result;
    }
    
    void backtrack(string& tiles, string curr, int& count, int index){
        
        cout<<"\npermuting.."<<curr;
        permute(curr, count, 0);
        
        if(index == tiles.size())
            return;        
        
        for(int i = index; i < tiles.size(); i++){
            curr.push_back(tiles[i]);
            backtrack(tiles, curr, count, i + 1);
            curr.pop_back();
            
            while(i < tiles.size() - 1 && tiles[i] == tiles[i + 1])        // because tiles are sorted
                i++;
        }
    }
    
    void permute(string& curr, int& count, int index){
        if(index == curr.size()){
            if(index > 0)
                count++;
            return;
        }
        
        unordered_set<char> s;
        for(int i = index; i < curr.size(); i++){
            if(s.find(curr[i]) != s.end())
                continue;
            
            s.insert(curr[i]);
            swap(curr[i], curr[index]);
            permute(curr, count, index + 1);
            swap(curr[i], curr[index]);
        }
    }  
};


/*
    Given a string "tiles", Find all its combination 
    Then for each combination find the permutations.
    Return count of all permutations.
    
    Ex: "AAB"
    
    Combination :   Permutations
            A   :   A
            B   :   B
            AB  :   AB, BA
            AA  :   AA
            AAB :   AAB, ABA, BAA
*/
