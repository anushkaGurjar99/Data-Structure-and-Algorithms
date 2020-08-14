/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution{
public:
    int maxScore(vector<int>& cardPoints, int k){
        
        vector<int> points;
        helper(points, cardPoints, k);
        
        int result, start, score;
        result = start = score = 0;
        
        for(int i = 0; i < points.size(); i++){
            score += points[i];
            
            if(i - start == k){
                score -= points[start];
                start++;
            }
            
            result = max(result, score);
        }
        
        return result;
    }
    
    void helper(vector<int>& points, vector<int>& c, int& k){
        
        int pos = k - 1;
        int size = c.size();
        
        while(pos >= 0){
            points.push_back(c[pos]);
            pos--;
        }
        
        pos = size - 1;
        int limit = k;
        while(limit > 0){
            limit--;
            points.push_back(c[pos]);
            pos--;
        }   
    }
};

/*
Approach: Sliding window

    Notice that by arranging the sequence we can actually obtain the K conseq valid accessible cards.
    
    Create a new array having the following elements:
        reverse order of first K elements.
        reverse order of last K elements.
        
    Apply the sliding window approach on K length window.
    
Example:
original array: 
    12  7   8   1   1   10  9   1
    0   1   2   3   4   5   6   7
    (k = 3)

newly created array:
    8   7   12  1   9   10
    0   1   2   3   4   5                                
*/

