/*
 
YODANESS LEVEL
Yoda is the wisest, and perhaps the most powerful Jedi of
his time. Yoda is a mysterious figure and he has many oddities. One of them is that Yoda often changes the order of words in the sentence. For example, one of such phrases is "Or I will
help you not." Let's call the yodaness level of any statement the number of pairs of words that changed their order, as to the order in which they were supposed to go in a normal
statement. Write a program that determines the yodaness level of different statement of Yoda.

INPUT
The first line of input contains the number t (1 <= t <= 10) - the number of tests. Next comes the description of t tests. Each test consists of three rows. The first line of the test
contains an integer n(1 <= n <= 30000) - number of words in the statement. The next line contains n words separated by spaces - the statement as Yoda says it. The next line is n words
separated by spaces - the same statement as it should be said normally. All the words in the statement are different and consist of small Latin letters. Also, the length of all words is
equal or less than 20.

OUPUT
For each test print the yodaness level of the statement.
SAMPLE INPUT AND OUTPUT

Input
2
6
in the force strong you are
you are strong in the force
6
or i will help you not
or i will not help you

Output
11
2

*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <map>

void update(int* Tree, int index, int s, int e, int num)
{
    if (s == num and e == num)
    {
        Tree[index] = 1;
        return;
    }

    if (num < s or num > e)
        return;

    int mid = (s + e) >> 1;
    update(Tree, 2 * index, s, mid, num);
    update(Tree, 2 * index + 1, mid + 1, e, num);

    Tree[index] = Tree[2 * index] + Tree[2 * index + 1];
}

int query(int* Tree, int index, int s, int e, int qs, int qe)
{

    if (qs <= s and e <= qe)
        return Tree[index];

    if (s > qe or e < qs)
        return 0;

    int mid = (s + e) >> 1;

    return query(Tree, 2 * index, s, mid, qs, qe) + query(Tree, 2 * index + 1, mid + 1, e, qs, qe);
}

int main(int argc, char const* argv[])
{
    int cases, nums;
    std::map<std::string, int> check;
    std::string yoda;
    scanf("%d", &cases);
    
    while(cases--)
    {
        scanf("%d", &nums);
        int arr[nums];
        for(int i = 0; i < nums; i++)
        {
            std::cin >> yoda;
            check[yoda] = i;
        }
        
        for(int i = 0; i < nums; i++)
        {
            std::cin >> yoda;
            arr[i] = check[yoda];
        }

        int mx = nums-1;
        int Tree[6 * mx];

        memset(Tree, 0, sizeof(Tree));

        int answer = 0;

        for (int i = 0; i < nums; ++i)
        {
            answer += query(Tree, 1, 1, mx, arr[i] + 1, mx);
            update(Tree, 1, 1, mx, arr[i]);
        }

        printf("%d\n",answer);
    }
    return 0;
}
