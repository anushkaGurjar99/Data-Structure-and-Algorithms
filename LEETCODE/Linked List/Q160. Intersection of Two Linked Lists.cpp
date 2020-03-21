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

// Problem Statement: https://leetcode.com/problems/intersection-of-two-linked-lists

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* one = headA;
        ListNode* two = headB;
        
        int flag = 0;
        
        while(one && two && one != two){
            one = one->next;
            two = two->next;
            
            if(!one && flag < 2){
                one = headB;
                flag++;
            }
            if(!two && flag < 2){
                two = headA;
                flag++;
            }
        }
        
        return (two == nullptr) ? two : one;
    }
};

/*
Flag insure that if there exist no cycle then loop should terminate.
Return statement: return the SECOND pointer if it is null, else return the FIRST (can be NULL or meeting point).
*/
