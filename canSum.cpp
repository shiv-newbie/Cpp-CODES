// canSum Function
/* Write a function cansum(targetsum, numbers) that takes in a targetsum
 and an array of numebrs as an argument.
 
 The function should return a boolean indicating wether or not it is popssible to geenrate the targetSum
 using numbers from the array
 
 You may use an element of the array as many times as needed & all numbers are non-negative
 */

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
map<long long int, long long int> wrong;
bool CanSum(long long int num, long long int matrix[], long long int size)
{
    if(num < 0)
    {
        return 0;
    }
    if(wrong.count(num))
        return 0;
    
    if (num == 0) return 1;
    
    for(int i = 0; i < size; i++)
    {
        long long int remainder = num - matrix[i];
        if(CanSum(remainder, matrix, size))
            return 1;
        else
            wrong[remainder] = 1;
    }
    return 0;
}

int main()
{
    long long int canSum, num;
    long long int matrix[1000];

    printf("Enter your canSum: ");
    scanf("%lld", &canSum);
    
    printf("Enter the number of values in your matrix: ");
    scanf("%lld", &num);
    
    printf("Enter the values in your matrix: ");
    for(int i = 0; i < num; i++)
    {
        scanf("%lld", &matrix[i]);
    }

    if(CanSum(canSum, matrix, num))
        printf("True\n");
    else
        printf("False\n");
    
    
    return 0;
}
