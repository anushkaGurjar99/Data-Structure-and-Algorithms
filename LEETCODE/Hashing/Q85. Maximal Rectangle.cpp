/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximal-rectangle/

/*
Similar problem: Max area in Histogram
take a vector of column size(with all values 0)
  
  keep adding the row[i] into vector and calculate area using Histogram method
*/


/*
Similar problem: Number of Island

Keep marking the area as '2' which is visited

what we need to do here is:
store Start and End of each row (containing 1) in a 2Dvector (region can be divided like [0 1 0 1 1 1 0 1 1 0])
after ending of the region, calculate the CURR_AREA of region and compare with RESULT

how to calculate CURR_AREA ? (maintain a leftBorder and rightBorder for simplicity)

// for better understanding DRY RUN yourself
