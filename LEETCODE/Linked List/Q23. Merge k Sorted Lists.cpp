/*
 * Author : Anushka Gurjar
 * Date   : April 2020
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

// Problem Statement: https://leetcode.com/problems/merge-k-sorted-lists/

typedef pair<int, ListNode*> P;
class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* trav = dummyHead;
        
        priority_queue<P, vector<P>, greater<P>> nodes;
        
        for(auto i: lists){
            ListNode* temp = i;
            if(temp)
                nodes.emplace(temp->val, temp);
        }
        
        while(!nodes.empty()){
            P curr = nodes.top();
            nodes.pop();
            
            if(curr.second->next){
                ListNode* next = curr.second->next;
                nodes.emplace(next->val, next);
            }
            trav->next = curr.second;
            trav = trav->next;
        }
        
        return dummyHead->next;
    }
};

/*
Approach:
    "we are using MIN heap here"
    
    store all Head Node into PQ(if exist)
    take a dummy Head for edge cases
    take a current node which is equal to dummyHead
    
    each time we pop element from PQ and follow these steps (till PQ has element)
        point current->next to TOP
        current is equal to TOP
        if current isn't tail then store its next node into PQ
        
    return dummyHead->next
*/


