/*
 * Author : Anuska Gurjar
 * Date   : Februaruy 2020
 * flags    : -std=c++14
*/
// Problem Statement: https://leetcode.com/problems/merge-sorted-array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int one = m - 1;
        int two = n - 1;
        int pos = m + n - 1;
        while(one >= 0 && two >= 0){
            if(nums1[one] > nums2[two]){
                nums1[pos] = nums1[one];
                one--;
            }
            else{
                nums1[pos] = nums2[two];
                two--;
            }
            pos--;
        }
        while(two >= 0){
            nums1[pos] = nums2[two];
            two--;
            pos--;
        }
    }
};
