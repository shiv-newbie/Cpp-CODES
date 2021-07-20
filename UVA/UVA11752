#include <cmath>
#include <map>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <iostream>
#define N 65
#define ll unsigned long long                       // Because long long is not enough to handle the numbers

using namespace std;

int nums[N], isTrue[N], cnt = 0;
set <ll> mySet;

ll exp(ll x,ll n)
{
    if(n == 0)
        return 1;
    ll pw = exp(x , n>>1);                          // Binary ceil division by 2
    pw = pw * pw;                                   // Compensation for binary ceil
    if(n & 1)                                       // if the exp was originally odd
        pw = pw * x;
    return pw;
}

void primeUtil()
{
    memset(isTrue, 1, sizeof(isTrue));

    for(int i = 2; i < N; i++)
    {
        if(isTrue[i])
            nums[++cnt] = i;

        for(int j = 1;(j <= cnt) && (nums[j] * i < N); j++)
        {
            isTrue[i*nums[j]] = 0;
            if(i%nums[j] == 0)
                break;
        }
    }
}

int main()
{

    primeUtil();

    mySet.clear();
    mySet.insert(1);                                        // Because (2, 3, 4, ...., N)^0 = 1

    double maxPow = log(pow(2.0,64.0) - 1);

    for(int i = 2; i < (1 << 16); i++)
    {
        int maxNum = ceil(maxPow / log(i));

        for(int j = 4; j < maxNum; j++)
            if(!isTrue[j])
            {
                ll num = exp(i, j);
                if(!mySet.count(num))
                    mySet.insert(num);
            }

    }

    for(set<ll>::iterator it = mySet.begin(); it != mySet.end(); it++)
        printf("%llu\n",*it);

    return 0;
}
