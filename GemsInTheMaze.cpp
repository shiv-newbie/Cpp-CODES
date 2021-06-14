// Code written by Shivam Haldiya

/*
 Gems in the maze
 
 Problem Statement
 Scrooge has a new plan how to increase his wealth. He found ancient ruins with an extraordinary maze. This maze consists of n chambers. The chambers are numbered 0
 through n− 1. Each chamber contains exactly one gem. Chambers are connected by one-way tunnels. Each chamber has exactly two outgoing tunnels: one leads to the
 chamber with number(a⋅v2 +b⋅v+c)mod n,the other will bring you out of the maze.
 
 You can enter the maze at any location, move along the tunnels and collect the gems. But once you leave the maze, you’ll trigger a self-destruct mechanism – the
 ceiling of the maze will collapse and all the gems that you did not collect will be lost forever. Scrooge wants to know the maximum number of gems he can take from
 the maze.
 
 Input
 The first line of the input contains an integer t specifying the number of test cases. Each test case is preceded by a blank line. Each test case consist of a single
 line containing four integers a, b, c (a,b,c ≤50) and n, n ≤ 300) – the numbers that describe one particular maze.
 
 Output
 For each test case, output a single line containing a single integer – the maximum number of gems that can be taken from the maze.
 
 Sample
 
 Input
3
1 2 0 64
0 2 1 47
0 3 5 128
 
 Output
 
 5
 23
 64
 */

#include <stdio.h>
#include <math.h>
#include <vector>

int a, b, c, num;


int cnt(std::vector<int> room, int a, int b, int c, int n, int num)
{
    // num = rooms
    // n = Total number of rooms
    
    room[num] = 1;
    int count = 0;
    
    int calc = (a*num*num + b*num + c)%n;
   
    if(room[calc] == 1)
        return 0;
    
    
    count++;
    
    
    count += cnt(room, a, b, c, n, calc);
    return count;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    
    
    
    while(cases--)
    {

        scanf("%d %d %d %d", &a, &b, &c, &num);
        int max = 0;
        for(int i = 0; i < num; i++)
        {
            if(i == 2)
                i = 2;
            std::vector<int> room(300, 0);
            int here = cnt(room, a, b, c, num, i);
            if(here > max)
                max = here;
        }
        printf("%d\n", max+1);
    }
    
    return 0;
}
