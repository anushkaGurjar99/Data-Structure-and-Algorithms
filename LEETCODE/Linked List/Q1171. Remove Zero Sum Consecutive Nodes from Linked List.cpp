/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
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

// Problem Statement: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/


class Solution{
public:
    ListNode* removeZeroSumSublists(ListNode* head){
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        while(helper(head, dummyHead))
            head = dummyHead->next;
        
        return dummyHead->next;
    }
    
    bool helper(ListNode* head, ListNode* dummyHead){
        unordered_map<int, ListNode*> m;
        int cf = 0;
        m[0] = dummyHead;
        
        while(head){
            cf += head->val;
            if(m.find(cf) != m.end()){
                ListNode* temp = m[cf];
                temp->next = head->next;
                return true;
            }
            m[cf] = head;
            head = head->next;
        }
        
        return false;
    }
};

/*
MAP contains:
    cf: node address
        
    2   2   -2  1   -1  -1
0   2   4   2   3   2   1

    1   3   2   -3  -2  5   5   -5  1
0   1   4   6   3   1   6   11  6   7


Delete the seq if valid, then start again from start.
We start from head again after a valid seq becuase their might exist expired cf and we don't need that
*/


