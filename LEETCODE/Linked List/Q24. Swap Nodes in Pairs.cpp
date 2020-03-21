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

// Problem Statement: https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    ListNode* swapPairs(ListNode* head){
        
        if(!head || !head->next)
            return head;
        
        ListNode* one = head;
        ListNode* two = head->next;
        
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        
        ListNode* prev = dummyHead;
            
        while(one && two){
            ListNode* nextNode = two->next;
            
            one->next = nextNode;           // connect ONE to unvisited list
            two->next = one;
            
            prev->next = two;
            prev = one;                     // because ONE comes ahead by swapping, we have to connect swapped node to prev list nodes
            one = nextNode;
            if(one)
                two = one->next;
        }
        
        return dummyHead->next;
    }
};
