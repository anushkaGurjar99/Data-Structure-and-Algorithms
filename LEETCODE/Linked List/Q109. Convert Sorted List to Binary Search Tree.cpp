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

// Problem Statement: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

class Solution{
public:
    TreeNode* sortedListToBST(ListNode* head){
        vector<int> nodes;
        getNodes(nodes, head);
        return helper(nodes, 0, nodes.size() - 1);
    }
    
    void getNodes(vector<int>& nodes, ListNode* head){
        while(head){
            nodes.push_back(head->val);
            head = head->next;
        }
    }
    
    TreeNode* helper(vector<int>& nodes, int l, int r){
        if(l > r)
            return nullptr;
        
        int mid = l + (r - l) / 2;
        
        TreeNode* newNode = new TreeNode(nodes[mid]);
        
        newNode->left = helper(nodes, l, mid - 1);
        newNode->right = helper(nodes, mid + 1, r);
        
        return newNode;
    }
};

/*
App1: convert into array then recuse to set nodes
App2: find mid using slow-fast ptr approach, set nodes parallelly.
*/

