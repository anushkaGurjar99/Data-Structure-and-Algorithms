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

// Problem Statement: https://leetcode.com/problems/reverse-linked-list

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* currNode = head;
        ListNode* prevNode = nullptr;
        
        while(currNode){
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        
        // currNode is null while prevNode is pointing to last node which is our head
        head = prevNode;
        
        return head;
    }
};

//****************************************** Recursive **************************************************

class Solution {
public:
    ListNode* reverseList(ListNode* head){   
        if(!head || !head->next)
            return head;
        
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
