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

// Problem Statement: https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head){
        
        if(!head || !head->next)
            return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        int hasCycle = false;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        
        ListNode* cycleStart = nullptr;
        if(hasCycle){
            ListNode* trav = head;
            
            while(trav != slow){
                trav = trav->next;
                slow = slow->next;
            }
            
            cycleStart = trav;
        }
        
        return cycleStart;
    }
};

// Explanation => https://www.quora.com/bookmarks
