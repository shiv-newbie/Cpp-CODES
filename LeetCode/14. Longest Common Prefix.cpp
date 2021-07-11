//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//
//
//Example 1:
//
//Input: strs = ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//
//Input: strs = ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
//
//
//Constraints:
//
//1 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] consists of only lower-case English letters.

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

string longestCommonPrefix(vector<string>& strs)
{
    if(strs.size() == 1)
        return strs[0];
    string s = "", f = strs[0];
    int h = int(f.size()-1);
    for(int i = 0; i < 200; i++)
    {
        bool isTrue = true;
        for(int j = 1; j < strs.size(); j++)
        {
            int k = int(strs[j].size()-1);

            if(k < i || h < i || strs[j][i] != f[i])
            {
                isTrue = 0;
                break;
            }
        }
        if(!isTrue)
            break;
        s += f[i];
    }
    return s;
}


int main()
{
    vector<string >strs = {"", ""};
    cout << longestCommonPrefix(strs);
    return 0;
}
