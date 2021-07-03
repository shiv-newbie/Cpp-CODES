// howSum Function
/*
 Write a function cansum(targetsum, numbers) that takes in a targetsum
 and an array of numebrs as an argument.
 
 The function should return an array containing any combinatino of elements that add up to exactly the targetSum. If there is no combination that
 adds up to the targetsum then return null.
 
 If there are multiple combinations possible, you may return any single one.
 */

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
map<long long int, long long int> wrong;
vector<long long int> all;
bool CanSum(long long int num, long long int matrix[], long long int size)
{
    if(num < 0)
    {
        return 0;
    }
    if(wrong.count(num))
        return 0;
    
    if (num == 0)
    {
        return 1;
    }
    
    for(int i = 0; i < size; i++)
    {
        long long int remainder = num - matrix[i];
        if(CanSum(remainder, matrix, size))
        {
            all.push_back(matrix[i]);
            return 1;
        }
        else
        {
            wrong[remainder] = 1;
        }
    }
    return 0;
}

int main()
{
    long long int canSum, num;
    long long int matrix[1000];

    printf("Enter your howSum: ");
    scanf("%lld", &canSum);
    
    printf("Enter the number of values in your matrix: ");
    scanf("%lld", &num);
    
    printf("Enter the values in your matrix: ");
    for(int i = 0; i < num; i++)
    {
        scanf("%lld", &matrix[i]);
    }

    
    
    if(CanSum(canSum, matrix, num))
    {
        printf("True: [");
        sort(all.begin(), all.end());
        for(int i = 0; i < all.size(); i++)
        {
            if(i == all.size()-1)
                break;
            printf("%lld, ", all[i]);
            
        }
        if(all.size() == 0)
            printf("]\n");
        else
            printf("%lld]\n", all[all.size()-1]);
    }
    else
    {
        printf("NULL\n");
    }
    
    
    return 0;
}
