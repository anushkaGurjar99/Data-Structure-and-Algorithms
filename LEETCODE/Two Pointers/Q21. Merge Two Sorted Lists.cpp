/*
 * Author : Anushka Gurjar
 * Date   : March 2020
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
// Problem Statement: https://leetcode.com/problems/merge-two-sorted-lists

// In place, just changing the pointers 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = l1;
        ListNode* prev = dummyHead;
        
        while(node1 && node2){
            if(node1->val < node2->val){
                prev = node1;
                node1 = node1->next;
            }
            else{
                ListNode* temp = node2;
                node2 = node2->next;
                temp->next = node1;
                prev->next = temp;
                prev = temp;
            }
        }
        
        if(node2)
            prev->next = node2;
    
        return dummyHead->next;
    }
};

