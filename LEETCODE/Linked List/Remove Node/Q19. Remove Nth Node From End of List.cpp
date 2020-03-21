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

// Problem Statement: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* trav = head;
        for(int i = 0; i < n; i++){                 // traverse n nodes from head
            trav = trav->next;
        }
        
        ListNode* target = head;
        
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        
        ListNode* prev = dummyHead;        
        
        while(trav){                                // after this whole loop target will be pointing to nth node from end
            trav = trav->next;
            prev = target;
            target = target->next;
        }
        
        prev->next = target->next;                  // remove the node
        delete target;
        
        return dummyHead->next;
    }
};
