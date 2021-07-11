//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
//
//Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
//I can be placed before V (5) and X (10) to make 4 and 9.
//X can be placed before L (50) and C (100) to make 40 and 90.
//C can be placed before D (500) and M (1000) to make 400 and 900.
//Given an integer, convert it to a roman numeral.
//
//
//
//Example 1:
//
//Input: num = 3
//Output: "III"
//Example 2:
//
//Input: num = 4
//Output: "IV"
//Example 3:
//
//Input: num = 9
//Output: "IX"
//Example 4:
//
//Input: num = 58
//Output: "LVIII"
//Explanation: L = 50, V = 5, III = 3.
//Example 5:
//
//Input: num = 1994
//Output: "MCMXCIV"
//Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
//
//
//Constraints:
//
//1 <= num <= 3999


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

string intToRoman(int num) {
    int j = num;
    string s = "";
    while(j > 0)
    {
        if(j >= 1000)
        {
            int l = j / 1000;
            for(int k = l; k > 0; k--)
                s += 'M';
            j -= l*1000;
        }
        if(j >= 100)
        {
            int k = j / 100;
            int l = k;
            if(k == 4)
                s+= "CD";
            else if(k == 9)
                s += "CM";
            else if(k < 4 )
            {
                for(int i = 0; i < k; i++)
                    s+= "C";
            }
            else if( k >= 5)
            {
                s += "D";
                for(int i = 0; i < k - 5; i++)
                    s += "C";
            }
            j-= l*100;
        }
        if(j >= 10)
        {
            int k = j / 10;
            int l = k;
            if(k == 4)
                s+= "XL";
            else if(k == 9)
                s += "XC";
            else if(k < 4 )
            {
                for(int i = 0; i < k; i++)
                    s+="X";
            }
            else if( k >= 5)
            {
                s += "L";
                for(int i = 0; i < k - 5; i++)
                    s += "X";
            }
            j-= l*10;
        }
        if(j >= 1 && j <= 9)
        {
            if(j == 4)
                s+= "IV";
            else if(j == 9)
                s += "IX";
            else if(j < 4 )
            {
                for(int i = 0; i < j; i++)
                    s+="I";
            }
            else if( j >= 5)
            {
                s += "V";
                for(int i = 0; i < j - 5; i++)
                    s += "I";
            }
            j -= j;
        }
    }
    return s;
}


int main()
{
    cout << intToRoman(1994);
    return 0;
}
