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

// Problem Statement: https://leetcode.com/problems/copy-list-with-random-pointer/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return head;        
        Node *current = head;
        
        // pass one, create a mapping
        while(current){
            Node *newNode = new Node(current->val, current->next, nullptr);
            current->next = newNode;
            current = newNode->next;
        }
        
        // fill the random pointer
        current = head;
        while(current){
            Node *currNext = current->next;
            if(current->random)
                currNext->random = current->random->next;
            current = currNext->next;
        }
        
        // restore the original list
        current = head;
        Node *newList = head->next;
        
        while(current){
            Node *currNext = current->next;
            current->next = currNext->next;
            current = current->next;
            if(current)
                currNext->next = current->next;
        }
        return newList;
    }
};


// ****************************************** using extra memory ***********************************************

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *prev = nullptr;
        Node *newHead = nullptr;
        unordered_map<Node*, Node*> cloneMap;
        
        while(head){
            Node *newNode = new Node(head->val, nullptr, head->random);
            cloneMap[head] = newNode;
            if(prev)
                prev->next = newNode;
            else
                newHead = newNode;
            prev = newNode;
            head = head->next;
        }
        
        head = newHead;
        while(head){
            head->random = cloneMap[head->random];
            head = head->next;
        }
        return newHead;
    }
};

