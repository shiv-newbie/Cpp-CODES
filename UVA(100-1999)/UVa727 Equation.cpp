//Equation
//Input and Output
//Write a program that changes an infix expression to a postfix expression according to the following specifications.
//1.
//The infix expression to be converted is in the input file in the format of one
//character per line, with a maximum of 50 lines in the file. For example,
//(3+2)*5 would be in the form:
//( 3 + 2 ) * 5
//2.
//The input starts with an integer on a line by itself indicating the number of test cases. Several infix expressions follows, preceded by a blank line.
//3.
//The program will only be designed to handle the binary operators +, -, *, /.
//4.
//The operands will be one digit numerals.
//5.
//The operators * and / have the highest priority. The operators + and - have the lowest priority. Operators at the same precedence level associate from left to right. Parentheses act as grouping symbols that over-ride the operator priorities.
//6.
//The output file will have each postfix expression all on one line. Print a blank line between different expressions.
//7.
//Each testcase will be an expression with valid syntax.
//Sample Input
//1
//( 3 + 2 ) * 5
//Sample Output
//32+5*
//
//Miguel Revilla 2000-08-31


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


int main()
{
    int num;
    scanf("%d", &num);
    string s = "", tmp;
    getline(cin, tmp);
    getline(cin, tmp);              // To take the empty space after the number input
    map<char, int> pre = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {'(', 0}};
    for(int i = 0; i < num; i++)
    {
        s = "";
        stack<int> check;
        while(getline(cin, tmp) && tmp.length() != 0)
        {
            s += tmp;
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                printf("%c", s[i]);
            else if(s[i] == '(')
                check.push('(');
            else if(s[i] == ')')
            {
                while(!check.empty() && check.top() != '(')
                {
                    printf("%c", check.top());
                    check.pop();
                }
                check.pop();
            }
            else
            {
                if(check.empty())
                    check.push(s[i]);
                else
                {
                    if(pre[s[i]] > pre[check.top()])
                        check.push(s[i]);
                    else
                    {
                        while(!check.empty() && pre[s[i]] <= pre[check.top()])
                        {
                            printf("%c", check.top());
                            check.pop();
                        }
                        check.push(s[i]);
                    }
                }
            }
        }
        while(!check.empty())
        {
            printf("%c", check.top());
            check.pop();
        }
        if(i != num -1)
            printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}



/*
1
 
(
3
+
2
)
*
5

 */
