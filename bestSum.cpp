#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;


map<int, vector<int>> memo;
vector<int> bestSum(int targetSum, int numbers[], int size)
{
	vector<int> remainderCombination;
	if (targetSum == 0) {
		remainderCombination.push_back(0);
		return remainderCombination;
	}
	if (targetSum < 0) {
		return remainderCombination;
	}

	vector<int> shortestCombination;

	for (int i = 0; i < size; i++)
	{
		int remainder = targetSum - numbers[i];
		if (memo.count(remainder) != 0)
			remainderCombination = memo[remainder];
		else
			remainderCombination = bestSum(remainder, numbers, size);
		if (remainderCombination.size() != 0)
		{
			vector<int> combination = remainderCombination;
			combination.push_back(numbers[i]);
			if (shortestCombination.size() == 0 || combination.size() < shortestCombination.size())
			{
				shortestCombination = combination;
			}
		}
	}

	memo[targetSum] = shortestCombination;
	return shortestCombination;
}


int main()
{
	int targetsum, size, num;
	printf("enter your targetsum: ");
	cin >> targetsum;
	printf("enter the number of items in the array: ");
	cin >> size;
	int numbers[1000];
	printf("enter the elements of your array: ");

	for (int i = 0; i < size; i++) {
		cin >> numbers[i];
	}
	

	vector<int> answer = bestSum(targetsum, numbers, size);
	if (answer.size() == 0)
		printf("null");
	else
	{
		printf("[");
		for (int i = 1; i < answer.size(); i++)
		{
			if (i == answer.size() - 1)
				break;
			printf("%d, ", answer[i]);
		}
		printf("%d]\n", answer[answer.size() - 1]);
	}
	return 0;
}
