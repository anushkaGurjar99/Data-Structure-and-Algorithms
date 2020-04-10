/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/compare-version-numbers/

string getVersion(string str, int& k){
    string num = "";
    
    while(k < str.length() && str[k] == '0')
        k++;
    
    while(k < str.length() && str[k] != '.'){
        num.push_back(str[k]);
        k++;
    }
    
    return num;
}

short whoIsGreater(short one, short two){
    short ret = 0;
    if(one > two)
        ret = 1;
    else if(one < two)
        ret = -1;
    return ret;
}

int Solution::compareVersion(string A, string B){
    
    if(A == "" && B == "")      // no comparision
        return 0;
    
    if(B == "")                             // first is greater
        return 1;
    
    if(A == "")                             // second is greater
        return -1;
    
    
    int result = 0;
    
    int i = 0;
    int j = 0;
    
    while(i < A.length() || j < B.length()){
        
        
        string one = getVersion(A, i);
        string two = getVersion(B, j);
        
        // If length is not same than we definitely found our answer (The one with shorter length is greater)
        
        result = whoIsGreater(one.length(), two.length());
        if(result != 0)
            break;

        for(int x = 0; x < one.length() && x < two.length(); x++){
            
            result = whoIsGreater(one[x] - '0', two[x] - '0');
            if(result != 0)
                break;
        }
        
        if(result != 0)
            break;
        
        i++;
        j++;
        
    }
    
    return result;
}


/*
Store each subVersion into string as it will never overflow (broder aspect of problem)

Approach: 
Cover the basic cases
then :
{
    get subVersion of both versions
    compare the length of subVersion (if different then exit with answer)
    
    compare each number of V1 to V2 and see whoIsGreater 
        (if greater found then exist with ansewer else check next number)
    
    (otherwise check next subVersion) 
}
*/



Another approch: https://leetcode.com/submissions/detail/322603693/
/* subVersion is stored in LONG which directly reduce the overhead of comparision, but interviewbit has overflow cases for the sol */

