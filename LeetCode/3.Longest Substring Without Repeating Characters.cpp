//Given a string s, find the length of the longest substring without repeating characters.
//
//
//
//Example 1:
//
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//Example 2:
//
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//Example 3:
//
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//Example 4:
//
//Input: s = ""
//Output: 0
//
//
//Constraints:
//
//0 <= s.length <= 5 * 10^4
//s consists of English letters, digits, symbols and spaces.




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


int main()
{
    string s = "ohvhjdml";                                  // The string input
    
    int mx = 0, tmp = 0;                                    // mx = max length recorded; tmp = temporary recording of length
    map<int, int> check;                                    // storing the last occurence of a character
    
    for(int i = 0; i < s.length(); i++)                     // iterating till the end of the array
    {
        if(check.count(s[i] - 'a') != 0)                    // if the char is found in the stored map
        {
            if(tmp > mx)                                    // recording the max length
                mx = tmp;
            tmp = 0;                                        // temporary recording of length back to 0
            if(i != check[s[i] - 'a'])                      // starting from the right of the point where the last our breaking char was
                i = check[s[i] - 'a'] + 1;
            check.clear();                                  // clearing the map
        }
        check[s[i] - 'a'] = i;                              // Recording in the map
        tmp++;
    }
    if(tmp > mx)
        mx = tmp;

    cout << mx;
}
