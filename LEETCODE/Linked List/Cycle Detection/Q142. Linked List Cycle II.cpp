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

class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        
        if(!head || !head->next)
            return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        
        ListNode* trav = head;
        while(slow && slow != trav){
            slow = slow->next;
            trav = trav->next;
        }
        
        return slow;
    }
};

// Explanation => https://www.quora.com/bookmarks
