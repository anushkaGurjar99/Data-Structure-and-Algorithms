/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/search-suggestions-system/ 

class Solution{
private:
    struct comparator{
        bool operator()(const string& one, const string& two){
            for(int i = 0; i < one.size() && i < two.size(); i++){
                if(one[i] != two[i])
                    return one[i] < two[i];
            }
            return one.size() < two.size();
        }
    }comp;
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord){
        
        sort(products.begin(), products.end(), comp);
        
        vector<vector<string>> result (searchWord.size());
        
        for(int i = 0; i < searchWord.size(); i++){
            string target = searchWord.substr(0, i + 1);
            
            for(int j = 0; j < products.size(); j++){
                string temp = products[j].substr(0, i + 1);
                
                if(target == temp)
                    result[i].push_back(products[j]);
                
                if(result[i].size() == 3)
                    break;
            }
            
        }
        
        return result;
    }
};

/*
Custom sort for lexicographical order.
Then check searchWord substring with input[i] substring. (store if match till search space < 3)
*/
