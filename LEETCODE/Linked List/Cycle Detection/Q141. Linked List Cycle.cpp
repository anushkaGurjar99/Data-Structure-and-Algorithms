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

// Problem Statement: https://leetcode.com/problems/linked-list-cycle/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!head || !head->next)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        
        return hasCycle;
    }
};

// floyd cycle detection algorithm
