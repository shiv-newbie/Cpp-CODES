// Total number of ways for moving right or down in a grid

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
long long int matrix[100][100];

long long int gridTraveller(long long int h, long long int w)
{
    if(matrix[h][w] != 0)
        return matrix[h][w] ;
    if(h == 1 && w == 1)
        return 1;
    if(h == 0 || w == 0)
        return 0;

    matrix[h][w] = gridTraveller(h-1, w) + gridTraveller(h, w-1);
    return matrix[h][w];
}

int main()
{
    long long int w, h;
    memset(matrix, 0, sizeof(matrix));
    printf("Please enter grid height and width: ");
    scanf("%lld %lld", &w, &h);

    printf("Total Number of ways are: %lld\n", gridTraveller(h, w));
    
    return 0;
}
