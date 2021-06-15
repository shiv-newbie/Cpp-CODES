/*
 Problem D: Dominos 2
 Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks
 down the one after that, all the way down the line. However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down
 by hand to get the dominos falling again.
 Given a set of dominos that are knocked down by hand, your task is to determine the total number of dominos that fall.
 Input Specification
 The first line of input contains one integer specifying the number of test cases to follow. Each test case begins with a line containing three integers
 n, m, l no larger than 10 000, followed by m+l additional lines. The first integer n is the number of domino tiles. The domino tiles are numbered from 1
 to n. Each of the m lines after the first line contains two integers x and y indicating that if domino number x falls, it will cause domino number y to
 fall as well. Each of the following l lines contains a single integer z indicating that the domino numbered z is knocked over by hand.
 
 Sample Input
 1
 3 2 1
 1 2
 2 3
 2
 
 Output Specification
 For each test case, output a line containing one integer, the total number of dominos that fall over.
 
 Output for Sample Input
 2
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>

int check[10000] = {0};
std::vector<int> graph[10000];

int dfs(int num, int check[10000])
{
    if(check[num] == 1)
        return 0;
    
    int count = 1;
    check[num] = 1;
       
    for(int i = 0; i < graph[num].size(); i++)
    {
        count += dfs(graph[num][i], check);
    }
    
    return count;
}

int main()
{
    
    int cases, n, m, x, y, hand, l;
    scanf("%d", &cases);
    
    while(cases--)
    {
        scanf("%d %d %d", &n, &m, &l);
        
        for(int i=0; i <= n; i++)
            graph[i].clear();
        
        int count = 0;
        while(m--)
        {
            scanf("%d %d", &x, &y);
            graph[x-1].push_back(y-1);
        }
        
        std::memset(check,0,sizeof(check));
        
        while(l--)
        {
            scanf("%d", &hand);
            if(!check[hand-1])
                count += dfs(hand-1, check);
        }
        
        printf("%d\n", count);
        
    }
    return 0;
}
