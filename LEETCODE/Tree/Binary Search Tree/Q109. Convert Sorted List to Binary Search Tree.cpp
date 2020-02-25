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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Problem Statement: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head){
        return createBST(head, nullptr);
    }
    TreeNode* createBST(ListNode* head, ListNode* tail){
        // 0 node
        if(!head)
            return nullptr;
        
        // 1 node
        if(head == tail)
            return new TreeNode(head->val);
        
        // 2 node
        if(head->next == tail){
            TreeNode* root = new TreeNode(head->val);
            root->left = nullptr;
            root->right = createBST(head->next, tail);
            return root;
        }
        
        // more than 2 nodes (calculate mid point to get Left subTree and right subTree)
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != tail && fast->next != tail){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = createBST(head, prev);
        root->right = createBST(slow->next, tail);
        return root;
    }
};

// Same as Array, each time calculate the mid point and link accordingly.
