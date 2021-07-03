// Fibonacci Sequence with Memoization

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
map<long long int, long long int> memo;

long long int fibbonaci(long long int num)
{
    if(memo.count(num) != 0)
        return memo[num];
    if(num <= 2) return 1;
    memo[num] = fibbonaci(num-1) + fibbonaci(num-2);
    return memo[num];
}

int main()
{
    long long int num;

    printf("Please enter your value: ");
    scanf("%lld", &num);
    printf("Your Fibbonaci Number is: %lld", fibbonaci(num));
    
    return 0;
}
