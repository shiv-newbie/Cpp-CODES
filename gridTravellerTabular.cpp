// gridTraveller - down Right traveller

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int w, h;
	int matrix[100][100];
	printf("enter the width and height: ");
	cin >> w >> h;
	memset(matrix, 0, sizeof(matrix));
	matrix[1][1] = 1;
	
	for (int i = 1; i <= w; i++)
	{
		for (int j = 1; j <= h; j++)
		{
			if(i+1 <= w)
				matrix[i + 1][j] += matrix[i][j];
			if(j+1 <= h)
				matrix[i][j + 1] += matrix[i][j];
		}
	}
	printf("%d", matrix[h][w]);
	return 0;
}
