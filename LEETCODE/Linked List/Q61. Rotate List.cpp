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

// Problem Statement: https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next)
            return head;
        
        int length = 0;
        ListNode* trav = head;
        ListNode* prev = nullptr;
        ListNode* lastNode;
        
        while(trav){                                  
            length++;
            lastNode = trav;
            trav = trav->next;
        }
        
        k = k % length;                                 // round the number of rotation
        
        if(k > 0){         
            trav = head;
            for(int i = 0; i < (length - k); i++){      // (lenght - k): from where to break the list
                prev = trav;
                trav = trav->next;
            }
            prev->next = nullptr;
            lastNode->next = head;
            head = trav;
        }
        
        return head;
    }
};
