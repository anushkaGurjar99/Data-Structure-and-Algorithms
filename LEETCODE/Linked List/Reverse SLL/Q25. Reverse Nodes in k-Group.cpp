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

// Problem Statement: https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        if(!head || !head->next || k == 1)
            return head;
        
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        
        ListNode* trav = head;
        ListNode* prevNode = dummyHead;
        
        while(trav){
            int count = 0;
            
            ListNode* kLeft = trav;
            ListNode* kRight = nullptr;
            ListNode* nextNode = nullptr;
            
            if(isValid(trav, kRight, k)){
                nextNode = kRight->next;
                reverseList(trav, k);
                
                prevNode->next = kRight;
                kLeft->next = nextNode;
                
                prevNode = kLeft;
                trav = nextNode;
            }
            else{
                break;   
            }
        }
        
        return dummyHead->next;
    }
    
    bool isValid(ListNode* curr, ListNode*& kRight, int limit){
        while(limit-- && curr){
            kRight = curr;
            curr = curr->next;
        }        
        return (limit == -1);
    }
    
    void reverseList(ListNode* trav, int K){
        ListNode* prev = trav;
        ListNode* curr = trav->next;
        
        while(K-- > 1){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
};

/*
Approach:
    Maintain 4 pointers
        kLeft    : start of list
        kRight   : end of list
        prevNode : just prev node of kLeft
        nextNode : just next node of kRight
        
    Check if we have K length available 
    If yes, 
        Reverse the (K - 1) length list and connect the pointers.
            prevNode->next will point to kRight
            kLeft->next will point to nextNode and become the prevNode for next iteration
            prevNode will now point to kRight
            current node will be updated to nextNode
    Else
        break, as we have not sufficient nodes to reverse.
*/





