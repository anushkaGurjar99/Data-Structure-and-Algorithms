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

// Problem Statement: https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    bool isPalindrome(ListNode* head){
        
        if(!head || !head->next)
            return true;
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        ListNode* join;
        int center = 0;
        
        while(fast && fast->next){
            join = slow;
            slow = slow->next;
            fast = fast->next->next;
            center++;
        }
        
        if(fast)               // for even len list
            center++;
        
        ListNode* midNode = reverseList(slow->next);    // reverse the half
        slow->next = midNode;                           // connect the reversed half
        
        ListNode* curr = head;
        
        for(int i = 0; i < center; i++){
            if(midNode->val != curr->val)
                return false;
            midNode = midNode->next;
            curr = curr->next;
        }
        
        midNode = reverseList(slow->next);             // restore the reversed half
        slow->next = midNode;                          // connect the original half
        
        return true;
    }
    
    
    ListNode* reverseList(ListNode* curr){
        
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
