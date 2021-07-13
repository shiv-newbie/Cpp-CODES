//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//
//
//Example 1:
//
//Input: s = "()"
//Output: true
//Example 2:
//
//Input: s = "()[]{}"
//Output: true
//Example 3:
//
//Input: s = "(]"
//Output: false
//Example 4:
//
//Input: s = "([)]"
//Output: false
//Example 5:
//
//Input: s = "{[]}"
//Output: true
//
//
//Constraints:
//
//1 <= s.length <= 104
//s consists of parentheses only '()[]{}'.

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


bool isValid(string s)
{
    stack<char> st;
    map<char, char> check = {{'{','}'}, {'[', ']'}, {'(', ')'}};
    for(int i = 0; i < s.length(); i++)
    {
        if(st.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else
        {
            if(check[st.top()] == s[i])
                st.pop();
            else
                return 0;
        }
    }
    if(!st.empty())
        return 0;
    return 1;
}

int main()
{
    cout << isValid("({");
    return 0;
}


