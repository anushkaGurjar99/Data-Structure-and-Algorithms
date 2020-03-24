/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums){
        
        if (nums.size() < 1)
            return -1;
        
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
		return slow;
    }
};

/*
1   3   4   2   2
0   1   2   3   4

The main idea is the same with problem Linked List Cycle II.
Use two pointers the fast and the slow. The fast one goes forward two steps each time, 
while the slow one goes only step each time. 
They must meet the same item when slow==fast. In fact, they meet in a circle, the duplicate number must
be the entry point of the circle when visiting the array from nums[0]. Next we just need to find the
entry point. We use a point(we can use the fast one before) to visit form begining with one step each
time, do the same job to slow. When fast==slow, they meet at the entry point of the circle
*/

