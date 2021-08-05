#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <set>
#define IsComp(n)  (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))

using namespace std;

const int MAX = 100000000;
const int LMT = 10000;
 
// array of data; each bit tells if a certain number is composite or not
int _c[(MAX>>6)+1];
vector<int> primes;
 

void prime_sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!IsComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                SetComp(j);
 
    primes.push_back(2);
    for (int i=3; i <= MAX; i += 2)
        if (!IsComp(i))
            primes.push_back(i);
}
 
bool is_prime(int n)
{
    if (n < 2 || n % 2 == 0) return false;
    return !IsComp(n);
}

int main()
{
    prime_sieve();

    int num, checker;
    
    while(scanf("%d", &num) != EOF)
    {
        if(num & 1)
        {
            if (num > 2 && is_prime(num-2))
                printf("%d is the sum of %d and %d.\n", num, 2, num - 2);
            else
                printf("%d is not the sum of two primes!\n", num);
        }
        else
        {
            checker = 1;
            for (int i = num/2; i >= 1; i--)
            {
                if (is_prime(i) && is_prime(num - i) && i != num - i)
                {
                    printf("%d is the sum of %d and %d.\n", num, min(i, num-i), max(num - i, i));
                    checker = 0;
                    break;
                }
            }
            if (checker)
                printf("%d is not the sum of two primes!\n", num);
        }
    }

    return 0;
}
