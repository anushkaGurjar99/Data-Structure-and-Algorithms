/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/add-binary/

class Solution{
public:
    string addBinary(string a, string b){
        
        string result;
        int i = a.size();
        int j = b.size();
        int carry = 0;
        
        while(i > 0 || j > 0 || carry == 1){
            
            int sum =   ((i > 0) ? a[--i] - '0' : 0) + 
                        ((j > 0) ? b[--j] - '0' : 0) + 
                        carry;
            
            if(sum == 1 || sum == 3)
                result.push_back('1');
            else
                result.push_back('0');
            
            carry = sum < 2 ? 0 : 1; 
        }
        reverse(result.begin(), result.end());
        
        return result;
        
    }
    
};

/*
Possible SUM values = 0,1,2,3
{0,1,3} sum = (sum % 2)
{2} sum = 0

if sum is greater than 1 than carry is = 1
*/
