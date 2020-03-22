/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Problem Statement: https://leetcode.com/problems/next-greater-node-in-linked-list

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
                
        if(!head)
            return {};
        if(!head->next)
            return {0};
        
        vector<int> result;
        ListNode *current = head;
        stack<pair<short int, int>> process; 
        
        int pos = 0;
        while(current){
            
            if(!process.empty() && process.top().second < current->val)
                getLarger(result, process, current->val);
            
            result.push_back(0);
            process.push({pos, current->val});
            pos++;
            current = current->next;
        }
        
        return result;
    }

    void getLarger(vector<int>& result, stack<pair<short int, int>>& process, int value){
        
        while(!process.empty() && process.top().second < value){
            result[process.top().first] = value;
            process.pop();
        }
    }
};
