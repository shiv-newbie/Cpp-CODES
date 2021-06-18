
/*
Risk
Risk is a board game in which several opposing players attempt to conquer the world. The gameboard consists of a world map broken up into hypothetical countries. During a player's turn, armies stationed in one country are only allowed to attack only countries with which they share a common border. Upon conquest of that country, the armies may move into the newly conquered country.
During the course of play, a player often engages in a sequence of conquests with the goal of transferring a large mass of armies from some starting country to a destination country. Typically, one chooses the intervening countries so as to minimize the total number of countries that need to be conquered. Given a description of the gameboard with 20 countries each with between 1 and 19 connections to other countries, your task is to write a function that takes a starting country and a destination country and computes the minimum number of countries that must be conquered to reach the destination. You do not need to output the sequence of countries, just the number of countries to be conquered including the destination. For example, if starting and destination countries are neighbors, then your program should return one.
The following connection diagram illustrates the first sample input.
Input
Input to your program will consist of a series of country configuration test sets. Each test set will consist of a board description on lines 1 through 19. The representation avoids listing every national boundary twice by only listing the fact that country I borders country J when I < J. Thus, the Ith line, where I is less than 20, contains an integer X indicating how many ``higher-numbered" countries share borders with country I, then X distinct integers J greater than I and not exceeding 20, each describing a boundary between countries I and J. Line 20 of the test set
contains a single integer ( ) indicating the number of country pairs that follow. The next N lines each contain exactly two integers ( ) indicating the starting and ending countries for a
possible conquest.
There can be multiple test sets in the input file; your program should continue reading and processing until reaching the end of file. There will be at least one path between any two given countries in every country configuration.
Output
For each input set, your program should print the following message ``Test Set #T" where T is the number of the test set starting with 1 (left-justified starting in column 11).
The next N
number of countries to conquer. The test result line should contain the start country code A right-justified in
T
lines each will contain the result for the corresponding test in the test set - that is, the minimum

columns 1 and 2; the string `` to " in columns 3 to 6; the destination country code B right-justified in columns 7 and 8; the string ``: " in columns 9 and 10; and a single integer indicating the minimum number of moves required to traverse from country A to country B in the test set left-justified starting in column 11. Following all result lines of each input set, your program should print a single blank line.
Sample Input
13
234 3456 16
17
2 12 13 18
2 9 10
1 11
1 11
2 12 17
1 14
2 14 15
2 15 16
1 16
1 19
2 18 19
1 20
1 20
5
1 20
29
19 5
18 19
16 20 42356 14
3 4 10 5 5 10 11 267 278
2 9 10 19
1 10
2 11 14
3 12
3 18
4 14
0
13 17 15
12 19 18
14
13
16 17
0
0
2 18 20 1 19
1 20
6
1 20
8 20
15 16 11 4
7 13
2 16
Sample Output
Test Set #1 1 to 20: 7 2to 9:5
19to 5:6

18 to 19: 2 16 to 20: 2
Test Set #2 1 to 20: 4 8 to 20: 5
15 to 16: 2 11to 4:1 7 to 13: 3 2 to 16: 4
Miguel A. Revilla 1998-03-10

*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

int check[20] = {0};

int dfs(std::vector<int> cities[19], int start, int dest, int check[20])
{
    int count = 0, var;
    
    if(start == dest)
        return 1;
    
    count += 1;
    
    check[start] = 1;
    int min = 99999999;
    for(int i = 0; i < cities[start].size(); i++)
    {
        if(!check[cities[start][i]])
        {
            var = dfs(cities, cities[start][i], dest, check);
            if(var < min && var != 0)
                min = var;
        }
    }
    check[start] = 0;
    if(min != 99999999)
        return count + min;
    return 0;
}

int main()
{
    int hello, num, cases = 1, x, y;;
    while(scanf("%d", &hello) != EOF)
    {
        
        std::vector<int> cities[20];


        while(hello--)
        {
            scanf("%d", &num);
            cities[0].push_back(num-1);
            cities[num-1].push_back(0);
        }

        
        for(int i = 2; i < 20; i++)
        {
            int num, cs;
            scanf("%d", &cs);
            while(cs--)
            {
                scanf("%d", &num);
                cities[i-1].push_back(num-1);
                cities[num-1].push_back(i-1);
            }
            
        }
        printf("Test Set #%d\n", cases);
        scanf("%d", &num);
        while(num--)
        {
            
            scanf("%d %d", &x, &y);
            for(int i = 0; i < 20; i++)
                check[i] = 0;
            printf("%2d to %2d:%2d\n", x, y, dfs(cities, x-1, y-1, check)-1);
        }
        cases++;
        printf("\n");
    }
    
    return 0;
}

