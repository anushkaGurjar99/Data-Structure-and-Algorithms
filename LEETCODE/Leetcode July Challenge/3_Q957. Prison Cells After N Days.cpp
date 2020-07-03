/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/prison-cells-after-n-days/

class Solution{
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N){
        if(N < 1)
            return cells;
        
        map<vector<int>, int> m;
        map<int, vector<int>> x;
        vector<int> temp(8, 0);        
        
        int pos = 0;
        
        m[cells] = pos, x[pos] = cells;
        
        while(N--){
            
            for(int i = 1; i < 7; i++)
                temp[i] = !(cells[i - 1] ^ cells[i + 1]);
            
            cells = temp, pos++;
            
            if(m.find(temp) != m.end())
                break;
            
            m[temp] = pos, x[pos] = temp;
        }
        
        if(N >= 0){
            int diff = pos - m[temp];           // m[temp] is our position where repeating seq. begins
            cells = x[ m[temp] + (N % diff)];   
        }
        
        return cells;
    }
};

/*
Note: Since unordered_map has some boundations for key (primtive data type only) so we'll use map.

Store all the current sequence from both sides (in map)
    sequence vector,    int         map m
    int,    sequence vector         map x
    
As soon as any sequence is found repeated,
    we calculate the number of existed elements between found at current pos
    then we calculate the Nth sequence (simple math: start + (limit % difference))
*/
