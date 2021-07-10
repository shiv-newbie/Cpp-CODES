//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//
//The overall run time complexity should be O(log (m+n)).
//
//
//
//Example 1:
//
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
//Example 2:
//
//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
//Example 3:
//
//Input: nums1 = [0,0], nums2 = [0,0]
//Output: 0.00000
//Example 4:
//
//Input: nums1 = [], nums2 = [1]
//Output: 1.00000
//Example 5:
//
//Input: nums1 = [2], nums2 = []
//Output: 2.00000
//
//
//Constraints:
//
//nums1.length == m
//nums2.length == n
//0 <= m <= 1000
//0 <= n <= 1000
//1 <= m + n <= 2000
//-106 <= nums1[i], nums2[i] <= 106

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <string.h>

using namespace std;

int k = 0;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    nums1.insert( nums1.end(), nums2.begin(), nums2.end() );
    sort(nums1.begin(), nums1.end());
    
    int size = int(nums1.size());
    float median;
    if((size >> 1) << 1 == size)
        median = (float(nums1[size/2-1] + nums1[size/2]))/float(2);
    else
        median = (nums1[size/2 + 1]);
    
    return median;
}

int main()
{
    vector<int> a = {1, 3}, b = {2};
    
    
    cout << findMedianSortedArrays(a, b);
    
    return 0;
}
