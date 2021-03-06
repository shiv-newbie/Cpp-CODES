//Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
//
//Notice that you may not slant the container.
//
//
//
//Example 1:
//
//
//Input: height = [1,8,6,2,5,4,8,3,7]
//Output: 49
//Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
//Example 2:
//
//Input: height = [1,1]
//Output: 1
//Example 3:
//
//Input: height = [4,3,2,1,4]
//Output: 16
//Example 4:
//
//Input: height = [1,2,1]
//Output: 2
//
//
//Constraints:
//
//n == height.length
//2 <= n <= 10^5
//0 <= height[i] <= 10^4



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

int maxArea(vector<int>& height)
{
    int r = int(height.size())-1, l = 0, mx = 0, tmp = 0;
    
    while(r > l)
    {
        tmp = (r-l)*min(height[r], height[l]);
        if(mx < tmp)
            mx = tmp;
        
        if(height[l] > height[r])
            r--;
        else
            l++;
    }
    
    return mx;
}


int main()
{
    vector<int> h = {4,3,2,1,4};
    cout << maxArea(h);
    return 0;
}
