// Fibonacci

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using ll = long long int;
using namespace std;

int canConstruct(string target, string wordBank[], int size)
{
	return 0;
}

int main()
{
	long long int num;
	long long int matrix[1000];
	printf("enter the index of fib you want: ");
	cin >> num;
	memset(matrix, 0, sizeof(matrix));
	matrix[1] = 1;
	for (int i = 2; i <= num; i++)
	{
		matrix[i] += matrix[i - 1];
		matrix[i + 1] += matrix[i - 1];
	}
	printf("%lld\n", matrix[num]);
	return 0;
}
