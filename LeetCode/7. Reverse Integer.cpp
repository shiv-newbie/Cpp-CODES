//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//
//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
//
//
//
//Example 1:
//
//Input: x = 123
//Output: 321
//Example 2:
//
//Input: x = -123
//Output: -321
//Example 3:
//
//Input: x = 120
//Output: 21
//Example 4:
//
//Input: x = 0
//Output: 0
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

int reverse(int x)
{
    long long int sign = 1, rev = 0, tmp = x;
    if(x < 0)
    {
        tmp *= -1;
        sign *= -1;
    }
    
    while(tmp > 0)
    {
        rev = rev*10 + tmp%10;
        tmp/=10;
    }
    if(rev >= INT_MAX || rev <= INT_MIN)
        rev = 0;
    
    return rev*sign;
}

int main()
{
    cout << reverse(-123);
    return 0;
}
