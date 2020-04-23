/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/k-closest-points-to-origin/

// using nth_element or partial sort
class Solution{
private:
    static int distance(const vector<int>& p){
        return p[0] * p[0] + p[1] * p[1];
    }
    
    static bool cmp(const vector<int>& p1, const vector<int>& p2){
        return distance(p1) < distance(p2);
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, const int& K){
        nth_element(points.begin(), points.begin() + K, points.end(), cmp);
        return vector(points.begin(), points.begin() + K);
    }
};

// ************************************************ MAX Heap ************************************************
typedef pair<int, int> P;
class Solution{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K){
        
        vector<vector<int>> result;
        
        priority_queue<P> pq;                       // MAX heap
        int pos = 0;
        
        for(auto i: points){
            int x = abs(i[0]);
            int y = abs(i[1]);
            int distance = (x * x) + (y * y);
            if(pq.size() < K){
                pq.push({distance, pos});
            }
            else if(distance < pq.top().first){
                pq.pop();
                pq.push({distance, pos});
            }
            pos++;
        }
        
        while(!pq.empty()){
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};

/*
priority_queue elements: distance, index
*/
