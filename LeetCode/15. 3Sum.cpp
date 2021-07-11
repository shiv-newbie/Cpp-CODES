//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//
//Notice that the solution set must not contain duplicate triplets.
//
//
//
//Example 1:
//
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
//Example 2:
//
//Input: nums = []
//Output: []
//Example 3:
//
//Input: nums = [0]
//Output: []
//
//
//Constraints:
//
//0 <= nums.length <= 3000
//-10^5 <= nums[i] <= 10^5

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
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    set<int> s;
    map<int, int> check;
    vector<vector<int>> all;
    map<vector<int>, int> c;

    for(int i = 0; i < nums.size(); i++)
    {
        if(check.count(nums[i]) != 0)
            check[nums[i]] += 1;
        else
            check[nums[i]] = 1;
    }
    
    if(check.size() == 3)
    {
        int sum = 0, isTrue = 0;
        for(map<int, int>::iterator it = check.begin(); it != check.end(); it++)
        {
            sum += it->first;
            if(it->first == 0)
                isTrue = 1;
        }
        map<int, int>::iterator it = check.begin();
        if(sum == 0)
            all.push_back({it->first, (++it)->first, (++it)->first});
        if(isTrue && check[0] >= 3)
            all.push_back({0, 0, 0});
        return all;
    }
    if(nums.size() > 2 && check[nums[0]] == nums.size())
    {
        if(nums[0] == 0)
            all.push_back({0, 0, 0});
        return all;
    }
    
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            int k = 0-nums[i]-nums[j];
            if(check.count(k) != 0)
            {
                if(k == nums[i] && k == nums[j] && check[k] < 3)
                    continue;
                if((k == nums[i] || k == nums[j]) && check[k] < 2)
                    continue;
            }
            else
                continue;
            vector<int> jud;
            jud.push_back(nums[i]); jud.push_back(nums[j]); jud.push_back(k);
            sort(jud.begin(), jud.end());

            if(c.count(jud) == 0)
            {
                c[jud] = 1;
                all.push_back({nums[i], nums[j], k});

            }
        }
    }

    return all;
}


int main()
{
    vector<int> kk = {-1, -1, 0, 0, 1, 1};
    vector<vector<int>> all = threeSum(kk);
    for(int i = 0; i < all.size(); i++)
    {
        for(int j = 0; j < all[i].size(); j++)
            cout << all[i][j] << " ";
        cout << endl;
    }
    return 0;
}
