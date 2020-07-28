/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-k-closest-elements/

class Solution{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        
        priority_queue<pair<int, int>> pq;
        vector<int> result (k, 0);
        
        for(int i = 0; i < arr.size(); i++){
            int diff = abs(x - arr[i]);
            
            if(pq.size() < k){
                pq.push({diff, arr[i]});
            }
            
            else if(pq.top().first > diff){
                pq.pop();
                pq.push({diff, arr[i]});
            }
        }
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        while(!pq.empty()){
            minHeap.push(pq.top().second);
            pq.pop();
        }
        
        for(int i = 0; i < k; i++){
            result[i] = minHeap.top();
            minHeap.pop();
        }
        
        return result;
    }
};

/*
Approach 2: using PQ 
            first we use MAX heap to store all K elements.
            then we use MIN heap to store resultant MAX heap.
            at last wo convert MIN heap into array.
*/


// ********************************************************* Using Binary search ************************************************************************
class Solution{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        
        int left = 0;
        int right = 0;
        if(arr[0] > x){
            left = k - 1;
            right = arr.size();
        }
        else if(arr[arr.size() - 1] < x){
            left = -1;
            right = arr.size() - k;
        }
        else{
            left = searchNearestOfX(arr, x);
            if(arr[left] == x && left - 1 >= 0 && left + 1 < arr.size())
                right = abs(x - arr[left - 1]) <= abs(x - arr[left + 1]) ? left - 1: left + 1;
            else
                right = left + 1;
            
            if(left > right)
                swap(left, right);
        }
        
        vector<int> result = getClosestElements(arr, left, right, x, k);
        sort(result.begin(), result.end());
        return result;
    }
    
    int searchNearestOfX(vector<int>& arr, int& target){
        int left = 0;
        int right = arr.size() - 1;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            
            if(arr[mid] == target)
                return mid;
            
            if(arr[mid] < target && arr[mid + 1] >= target)
                return mid;
            
            if(arr[mid] < target && arr[mid + 1] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return left;
    }
    
    vector<int> getClosestElements(vector<int>& arr, int left, int right, int x, int k){
        vector<int> result;
        
        while(k-- > 0){
            if(left == -1){
                result.push_back(arr[right]);
                right++;
            }
            else if(right == arr.size()){
                result.push_back(arr[left]);
                left--;    
            }
            else{
                if(abs(x - arr[left]) <= abs(x - arr[right])){
                    result.push_back(arr[left]);
                    left--;
                }
                else{
                    result.push_back(arr[right]);
                    right++;
                }
            }
        }
        
        return result;
    }
};

// time: O(logN) + O(NlogN), space: O(1)
/* 
  we can improve time if we try to maintain sorted seq
  
  Approach:
    we find two points left and right which is the closest to the target, where left < right.
    then we calculat further k closest elements using these 2 pointers.
    finally we return the sorted order of extracted elements.
*/
