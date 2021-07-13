//17. Letter Combinations of a Phone Number
//Medium
//
//6644
//
//548
//
//Add to List
//
//Share
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
//
//
//Example 1:
//
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//Example 2:
//
//Input: digits = ""
//Output: []
//Example 3:
//
//Input: digits = "2"
//Output: ["a","b","c"]
//
//
//Constraints:
//
//0 <= digits.length <= 4
//digits[i] is a digit in the range ['2', '9'].

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

void bfs(int p, int len, string str, vector<string> &s, string &D, string all[8])
{
    if(p == len)
        s.push_back(str);
    else
    {
        string l = all[(D[p]-'0')-2];
        for(int i = 0; i < l.length(); i++)
        {
            bfs(p+1, len, str+l[i],s , D, all);
        }
    }
}

vector<string> letterCombinations(string digits) {
    
    string all[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    int len = int(digits.length());
    vector<string> s;
    if(!len)
        return s;
    bfs(0, len, "", s, digits, all);
    return s;
}




int main()
{
    
    string k = "28";
    vector<string> s = letterCombinations(k);
    
    for(int i = 0; i < s.size(); i++)
    {
        cout << s[i] << endl;
    }

}


