//Given a string s, return the longest palindromic substring in s.
//
//
//
//Example 1:
//
//Input: s = "babad"
//Output: "bab"
//Note: "aba" is also a valid answer.
//Example 2:
//
//Input: s = "cbbd"
//Output: "bb"
//Example 3:
//
//Input: s = "a"
//Output: "a"
//Example 4:
//
//Input: s = "ac"
//Output: "a"
//
//
//Constraints:
//
//1 <= s.length <= 1000
//s consist of only digits and English letters (lower-case and/or upper-case),

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

string longestPalindrome(string s) {
    if(s.length() == 1)
        return s;
    
    int j = 1, tmp = 0, idx = 0, size = 0, type = -1;
    for(int i = 1; i < s.length(); i++)
    {
        
        j = 1, tmp = 0;
        if(s[i] == s[i-1])       // even distribution  321123  => type 1
        {
            tmp++;
            while(i-j-1 >= 0 && i+j < s.length())
            {
                if(s[i-j-1] == s[i+j])
                    tmp++;
                else
                    break;
                j++;
            }
            if(2*tmp > size)
            {
                type = 1;
                idx = i;
                size = 2*tmp;
            }
        }
        
        j = 2, tmp = 0;
        
        if(s[i-1] == s[i+1])        // odd distribution   12321 => type 0
        {
            tmp++;
            while(i-j >= 0 && i+j < s.length())
            {
                if(s[i-j] == s[i+j])
                    tmp++;
                else
                    break;
                j++;
            }
            if(2*tmp + 1 > size)
            {
                idx = i;
                type = 0;
                size = 2*tmp + 1;
            }
        }
    }
    
    string str = "";
    if(size == 0)
        return str+s[0];

    if(type == 0)
    {
        for(int i = idx-size/2; i <= idx+size/2; i++)
        {
            str += s[i];
        }
    }
    else if(type == 1)
    {
        for(int i = idx-size/2; i < idx+size/2; i++)
        {
            str += s[i];
        }
    }
    
    return str;
}

int main()
{
    cout << longestPalindrome("bb");
    return 0;
}
