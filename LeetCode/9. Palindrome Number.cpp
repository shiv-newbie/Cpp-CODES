//Given an integer x, return true if x is palindrome integer.
//
//An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
//
//
//
//Example 1:
//
//Input: x = 121
//Output: true
//Example 2:
//
//Input: x = -121
//Output: false
//Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//Example 3:
//
//Input: x = 10
//Output: false
//Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//Example 4:
//
//Input: x = -101
//Output: false
//
//
//Constraints:
//
//-2^31 <= x <= 2^31 - 1


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

bool isPalindrome(int x)
{
    if(x < 0)
        return 0;
    int i = 0, j = x;
    map<int , int> myMap;
    while(j != 0)
    {
        myMap[i] = j%10;
        j/=10;
        i++;
    }
    i--;
    int k = 0;
    bool isTrue = true;
    for(j = 0; j <= (i/2)+1; j++)
    {
        if(myMap[j] == myMap[i-j])
        {
            k++;
        }
        else
        {
            isTrue = false;
            break;
        }
    }
    return isTrue;
}
int main()
{
    cout << isPalindrome(12521);
    return 0;
}
