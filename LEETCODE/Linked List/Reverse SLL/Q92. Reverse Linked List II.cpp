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

// Problem Statement: https://leetcode.com/problems/reverse-linked-list-ii/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(!head || !head->next || m == n)
             return head;
          
        ListNode* current = head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* beforeM = dummyHead;
      
        for(int i = 1; i < m; i++){
            beforeM = current;
            current = current->next;      
        }
      
        ListNode* afterN = nullptr;
        ListNode* reversed = reverseSublist(current, n - m, afterN);
      
        beforeM->next = reversed;
        current->next = afterN;                // current = Bth node
      
        return dummyHead->next;
    }
    
    
    ListNode* reverseSublist(ListNode* currentNode, int len, ListNode*& afterN){
        ListNode* prevNode = nullptr;
        while(len >= 0){
            ListNode* nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
            len--;
            afterN = nextNode;
        }
        return prevNode;
    }
};
