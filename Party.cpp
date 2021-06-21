/*
 Party
 N people came to a party. Then those, who had no friends among people at the party, left. Then those, who had exactly 1 friend among those who stayed, left as well. Then those, who had exactly 2, 3, ..., N - 1 friends among those who stayed by the moment of their leaving, did the same.
 What is the maximum amount of people that could stay at the party in the end?
 Input
 The first input line contains one number T — amount of tests (1 ≤ T ≤ 105). Each of the following T lines contains one integer number N (1 ≤ N ≤ 105).
 Output
 For each test output in a separate line one number — the maximum amount of people that could stay in the end.
 Sample
 Input Output
 Explanation
 For N = 3, if the friend structure is: people A and people B are friends, and people A and people C are friends, but people B and people C are NOT friends.
 After the “leaving process”, only people A will stay. This friend structure can give maximum number of people stay at the end.
 */

#include <stdio.h>

int main()
{
    int cases, i;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d", &i);
        i<=2 ? printf("0\n") : printf("%d\n", i-2 );
    }
    return 0;
}
