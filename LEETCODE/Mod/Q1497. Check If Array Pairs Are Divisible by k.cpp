/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k){
        
        unordered_map<int, queue<int>> m;
        unordered_set<int> v;
        
        getMod(m, arr, k);        
        
        for(int i = 0; i < arr.size(); i++){ 
            if(v.find(i) != v.end())
                continue;
            
            int curr = arr[i] % k;
            curr = (curr < 0) ? k + curr : curr;
            int target = (k - curr) % k;
            
            v.insert(i);
            m[curr].pop();
            
            if(m[target].size() < 1)
                return false;
            
            v.insert(m[target].front());
            m[target].pop();
        }
        
        return true;
    }
    
    void getMod(unordered_map<int, queue<int>>& m, vector<int>& arr, int& k){
        for(auto i = 0; i < arr.size(); i++){
            int temp = arr[i] % k;
            temp = (temp < 0) ? k + temp : temp;
            m[temp].push(i);
        }
    }
    
};

/*
Approach:
    Store mod of all elements in a map (use a Queue for track of index)
        mod: respected index
        
        Ex. [-4, -7, 5, 2, -8, 4]      k = 3
              0   1  2  3   4  5
            
            2 :     0, 1, 2, 3
            1 :     4, 5

    In next step
    Traverse the array linearly and check the required pair element.
        
        one = mod of current element
        two = (k - mod of one) % k      #handle some edge cases here (ex. one = 0, two should be 0)
        
        mark the top of one visited
        pop one                         #this must be done before searching two (ex. one = 0)
        
        if two exist in map -> mark the top of two visited, pop two
        else                -> return false
        
        Ex. 
            pair 1: {0, 4}
            pair 2: {1, 5}
            pair 3: couldn't find pair for index 3 (return false)
*/
