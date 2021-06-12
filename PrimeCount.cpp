#include <iostream>
#include <math.h>
#include <time.h>

bool isPrime(int prime)
{
    if(prime <= 3) return 1;
    else
    {
        if(prime % 2 == 0)return 0;
        for(int i = 3; i < sqrt(prime) + 1; i+=2)
        {
            if(prime % i == 0)
                return 0;
        }
        return 1;
    }
}

int main() {

    int num;
    printf("Enter a number: ");
    long u = clock();
    std::cin >> num;
    int count = 1;
    for(int j = 3; j < num; j+=2)
    {
        count += isPrime(j);
    }
    long v = clock();
    printf("%d\n",count);
    printf("Time Elapsed: %.2f sec\n", (float) (v-u)/CLOCKS_PER_SEC);

}
