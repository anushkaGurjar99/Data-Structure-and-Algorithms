/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximal-rectangle/

/*
Similar problem: Number of Island

what we need to do here is:
store Start and End of each row (containing 1) in a vector
after ending of the region, calculate the CURR_AREA of region and compare with RESULT

how to calculate CURR_AREA ? (maintain a leftBorder and rightBorder for simplicity)
left = right = -1

    if(borders does not exist OR are not same as prev)
      area = (right - left + 1)
      result = max(area, result)
      match = 1;
      
      // update the borders 
      left = first, right = second
    else
      match++;
      result = max(result, area * match);
    
if arr[i + 1th] area's border matches with prev border then simply add the region in result else calculate and compare with result.
*/


// for better understanding DRY RUN yourself
