// Dijkstra’s Algorithm

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int visited[5] = {1, 0, 0, 0, 0};

void dijastras(int all[5][5], int num)
{
    int count = 0, here = 0;
    printf("%d -> ", num);
    while(count != 4)
    {
        int my_min = INT_MAX;
        for(int i = 0; i < 5; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < 5; j++)
                {
                    if(!visited[j] && all[i][j] != 0 && all[i][j] < my_min)
                        here = j, my_min = all[i][j];
                }
            }
        }
        visited[here] = 1;
        printf("%d -> ", (here+1));
        count++;
    }
}

int main()
{
    int all[5][5] =
    {
        {0, 2, 6, 0, 0},
        {2, 0, 3, 5, 0},
        {6, 3, 0, 4, 1},
        {0, 5, 4, 0, 5},
        {0, 0, 1, 5, 0}
    };
    
    dijastras(all, 1);
    return 0;
}
