#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

long int cache[1500000] = { 0 };

long int next(long int num)
{
	if (((num >> 1) << 1) == num)
		return num / 2;
	else
		return 3 * num + 1;
}

long int cycleLen(long int num)
{
	if (num == 1)
		return 1;

	if (num < 1500000 && cache[num] != 0)
		return cache[num];

	int x = cycleLen(next(num)) + 1;
	if (num < 1500000)
		cache[num] = x;

	return x;
}

int main()
{
	long int n1, n2, from, to, mx, i, len;
	while (scanf("%ld %ld", &n1, &n2) != EOF)
	{

		if (n1 > n2)
		{
			from = n2;
			to = n1;
		}
		else
		{
			from = n1;
			to = n2;
		}
		
		mx = 0;
		printf("%d %d ", n1, n2);
		for (i = to; i >= from; i--)
		{
			if (i < (to / 2) - 1)
				break;
			
			len = 0;
			if (cache[i] != 0)
				len = cache[i];
			else
				len = cycleLen(i);

			if (len > mx)
				mx = len;
		}

		printf("%d\n", mx);

	}
	return 0;
}
