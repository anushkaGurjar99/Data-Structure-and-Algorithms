/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums){
        
        string result;
        vector<string> data(nums.size());
        
        for(int i = 0; i < nums.size(); i++)
            data[i] = to_string(nums[i]);
        
        sort(data.begin(), data.end(), [](string& one, string& two) {return one + two > two + one;});
        
        for(auto token: data)
            result.append(token);
        
        return result[0] == '0' ? "0" : result;
    }
};

/*
Using custom Sort
Ex: [33, 34, 3, 5, 9, 1]

    for place one:
        3334 > 3433     No
                        so we return 34
        
        343 > 334       Yes
                        first position still remain for 34
                        
        345 > 534       No
                        so we return 5
                        
        59 > 95         No
                        so we return 9
                        
        91 > 19         Yes
                        first position still remain for 9
    ____________________________________________________________________________________
    
    same calculation for all other places...
*/

// *****************************************************************************************************************************

class Solution {
public:
    struct comparator{
        bool operator() (string& one, string& two){
            return one + two > two + one;
        }    
    }obj;
    
    string largestNumber(vector<int>& nums){
        
        string result;
        vector<string> data(nums.size());
        
        for(int i = 0; i < nums.size(); i++)
            data[i] = to_string(nums[i]);
        
        sort(data.begin(), data.end(), obj);
        
        for(auto token: data)
            result.append(token);
        
        return result[0] == '0' ? "0" : result;
    }
};

/*
Note: For inbuild sort comparator you have to make structure object
*/
